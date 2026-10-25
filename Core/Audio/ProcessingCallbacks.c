#include "ProcessingCallbacks.h"
#include "Audio/AudioData.h"
#include "Audio/AudioManager.h"
#include "GlobalContext.h"
#include <rxi-log/log.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

void* decoder_thread_proc(void* params)
{
	atomic_store(&GlobalContextCore.decoder_thread_isRunning, true);
	
	execute_decoder_processing();
	
	atomic_store(&GlobalContextCore.decoder_thread_isRunning, false);
	return NULL;
}

void execute_decoder_processing()
{
	ma_decoder decoder;
	ma_decoder_config decoderConfig = ma_decoder_config_init(ma_format_f32, 2, 44100);

	if(ma_decoder_init_file(GlobalContextCore.AudioContext.filepath, &decoderConfig, &decoder) != MA_SUCCESS)
	{
		log_fatal("Decoder has failed to initialize and open file (%s).", GlobalContextCore.AudioContext.filepath);
		atomic_store(&GlobalContextCore.AudioContext.decoder_is_done, true);
		return; 
	}
	log_info("Decoder has started successfully .");

	while(atomic_load(&GlobalContextCore.AudioContext.decoder_is_done) == false)
	{
		
		if(atomic_load(&GlobalContextCore.AudioContext.is_started) == false)
		{
//			ma_pcm_rb_reset(&GlobalContextCore.AudioContext.rb);
			log_trace("Called STOPEVENT in THREAD.");
			break;
		}

		if(atomic_load(&GlobalContextCore.AudioContext.is_paused) == true)
		{
			ma_event_wait(&GlobalContextCore.AudioContext.pause_event);


			if(atomic_load(&GlobalContextCore.AudioContext.is_started) == false)
			{
				ma_pcm_rb_reset(&GlobalContextCore.AudioContext.rb);
				break;
			}
		}

		ma_uint32 framesToWrite = 8192;
		void* pBufferOutput = NULL;
		ma_result result = ma_pcm_rb_acquire_write(&GlobalContextCore.AudioContext.rb, &framesToWrite, &pBufferOutput);
		if(result != MA_SUCCESS || framesToWrite == 0)
		{
			usleep(10*1000);	
			continue;
		}

		ma_uint64 framesToRead = 0;
		ma_result res = ma_decoder_read_pcm_frames(&decoder, pBufferOutput, framesToWrite, &framesToRead);
		ma_pcm_rb_commit_write(&GlobalContextCore.AudioContext.rb, (ma_uint32)framesToRead);
	
		if(res != MA_SUCCESS || framesToRead == 0)
		{
			log_info("Decoder has reached end of file");
			break;
		}
		/*ma_uint32 available_pcm_frames = ma_pcm_rb_available_write(&GlobalContextCore.AudioContext.rb);
		if(available_pcm_frames < 8192)
		{
			usleep(10*1000);
		}*/
	}
	ma_decoder_uninit(&decoder);
	atomic_store(&GlobalContextCore.AudioContext.decoder_is_done, true);
}

void audio_processing_callback(ma_device *Device, void *Output, const void *Input, ma_uint32 frameCount)
{
	if(Device == NULL /*|| Device->pUserData == NULL*/)
	{
		log_error("Failure on audio_processing_callback (Device OR pUserData == NULL)");
		return;
	}
	
	GlobalContextCore.AudioContext.decoder.pUserData = Device->pUserData;
	
	ma_uint32 framesToRead = frameCount;
	void* pBufferInput = NULL;

	ma_result res = ma_pcm_rb_acquire_read(&GlobalContextCore.AudioContext.rb, &framesToRead, &pBufferInput);
	if(res != MA_SUCCESS)
	{
		log_error("Failed to acquire reading from ring buffer .");
		return;
	}
	else 
	{
		ma_copy_pcm_frames(Output, pBufferInput, framesToRead, ma_format_f32, 2);
		ma_pcm_rb_commit_read(&GlobalContextCore.AudioContext.rb, framesToRead);
	}

	if(framesToRead < frameCount)
	{
		ma_uint32 missingFrames = frameCount - framesToRead;
        	float* pSilenceStart = (float*)Output + (framesToRead * 2); // 2 channels (stereo)
        	memset(pSilenceStart, 0, missingFrames * 2 * sizeof(float));
	}
	(void)Input;	
}

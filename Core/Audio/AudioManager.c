#include "AudioManager.h"
#include "Audio/AudioData.h"
#include "Audio/ProcessingCallbacks.h"
#include "GlobalContext.h"
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <rxi-log/log.h>

bool AudioManager_Init()
{
	atomic_init(&GlobalContextCore.AudioContext.decoder_is_done, false);
	atomic_init(&GlobalContextCore.AudioContext.is_started, false);
	atomic_init(&GlobalContextCore.AudioContext.is_paused, false);
	atomic_init(&GlobalContextCore.decoder_thread_isRunning, false);

	ma_event_init(&GlobalContextCore.AudioContext.pause_event);
	
	ma_uint32 BufferCapacityInFrames = 44100 * 2;
	ma_result res = ma_pcm_rb_init(ma_format_f32, 2, BufferCapacityInFrames, NULL, NULL, &GlobalContextCore.AudioContext.rb);
	if(res != MA_SUCCESS)
	{
		log_error("Failed to initialize PCM Ring buffer");
		return false;
	}

	ma_device_config devcfg = ma_device_config_init(ma_device_type_playback);
	devcfg.playback.format = ma_format_f32;
	devcfg.playback.channels = 2;
	devcfg.sampleRate = 44100;
	devcfg.dataCallback = &audio_processing_callback;
	//devcfg.pUserData = NULL;
	GlobalContextCore.AudioContext.deviceConfig = devcfg;

	ma_result res0 = ma_device_init(NULL, &GlobalContextCore.AudioContext.deviceConfig, &GlobalContextCore.AudioContext.device);
	if(res0 != MA_SUCCESS)
	{
		log_error("Failed to initialize Audio device .");
		ma_pcm_rb_uninit(&GlobalContextCore.AudioContext.rb);
		return false;
	}
	return true;
}

void AudioManager_Deinit()
{
	atomic_store(&GlobalContextCore.AudioContext.is_started, false);
	atomic_store(&GlobalContextCore.AudioContext.decoder_is_done, true);
	// it's better to make a simple Threads Manager for threads	
	pthread_join(GlobalContextCore.decoder_thread_handle, NULL);

	ma_device_uninit(&GlobalContextCore.AudioContext.device);
	ma_pcm_rb_uninit(&GlobalContextCore.AudioContext.rb);
	ma_event_uninit(&GlobalContextCore.AudioContext.pause_event);


}

void AudioManager_CallPlay()
{
	
	atomic_store(&GlobalContextCore.AudioContext.is_started, true);
	atomic_store(&GlobalContextCore.AudioContext.decoder_is_done, false);
	pthread_create(&GlobalContextCore.decoder_thread_handle, NULL, decoder_thread_proc, NULL);
	ma_device_start(&GlobalContextCore.AudioContext.device);
	return;
}

void AudioManager_CallPause()
{
	atomic_store(&GlobalContextCore.AudioContext.is_paused, true);
	ma_device_stop(&GlobalContextCore.AudioContext.device);
}

void AudioManager_CallResume()
{
	atomic_store(&GlobalContextCore.AudioContext.is_paused, false);
	ma_event_signal(&GlobalContextCore.AudioContext.pause_event);
	ma_device_start(&GlobalContextCore.AudioContext.device);
}

void AudioManager_CallStop()
{
	if(atomic_load(&GlobalContextCore.decoder_thread_isRunning) == false)
	{
		log_warn("The Decoder Thread is not even running to stop .");

		atomic_store(&GlobalContextCore.AudioContext.is_started, false);
		ma_device_stop(&GlobalContextCore.AudioContext.device);
		return;
	}
	atomic_store(&GlobalContextCore.AudioContext.is_started, false);
	ma_pcm_rb_reset(&GlobalContextCore.AudioContext.rb);
	pthread_join(GlobalContextCore.decoder_thread_handle, NULL);
	ma_device_stop(&GlobalContextCore.AudioContext.device);
}

bool AudioManager_IsPaused()
{
	return atomic_load(&GlobalContextCore.AudioContext.is_paused);
}

bool AudioManager_IsStopped()
{
	bool var = atomic_load(&GlobalContextCore.AudioContext.is_started);
	if(var == true) return false;

	return true;
}

bool AudioManager_SwitchSoundFile(const char *filepath)
{
	if(filepath == NULL) return false;

	if(atomic_load(&GlobalContextCore.decoder_thread_isRunning) == false)
	{
		log_warn("The Decoder thread is not running or initialized .");
		
	}

	FILE* file = fopen(filepath, "r");
	if(!file)
	{
		log_error("the specified file does not exist (%s).", filepath);
		return false;
	}
	fclose(file);

	if(AudioManager_IsStopped() == false)
	{
		AudioManager_CallStop();
	}
	
	strncpy(GlobalContextCore.AudioContext.filepath, filepath, sizeof(GlobalContextCore.AudioContext.filepath));
	return true;
}

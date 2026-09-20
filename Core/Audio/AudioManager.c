#include "AudioManager.h"

static void audio_callback(ma_device *device, void *Output, const void *Input, ma_uint32 frameCount)
{
	ma_decoder* decoder = (ma_decoder*)device->pUserData;
	if(decoder == NULL)
		return;

	ma_decoder_read_pcm_frames(decoder, Output, frameCount, NULL);
	(void)Input;


	// TODO: Check Gemini Docs , try to read to understand Audio Ring Buffer
	// or check miniaudio's ring buffer
}

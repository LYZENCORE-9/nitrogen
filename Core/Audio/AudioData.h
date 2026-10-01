#pragma once

#include <miniaudio/miniaudio.h>
#include <stdatomic.h>

typedef struct AudioData
{
	ma_device_config deviceConfig;
	ma_decoder decoder;
	ma_device device;

	ma_pcm_rb rb;

	char filepath[1024];

	atomic_bool decoder_is_done;
	//atomic_bool is_stop_requested;

	atomic_bool is_started; // true playing , false stopped
	atomic_bool is_paused;

	ma_event pause_event;



} AudioData;

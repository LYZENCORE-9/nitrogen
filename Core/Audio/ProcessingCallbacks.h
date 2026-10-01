#pragma once
#include "AudioData.h"

void audio_processing_callback(ma_device* Device, void* Output, const void* Input, ma_uint32 frameCount);

void execute_decoder_processing(void);
void* decoder_thread_proc(void* params);

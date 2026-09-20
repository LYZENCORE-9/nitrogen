#pragma once
#include <stdbool.h>
#include <miniaudio/miniaudio.h>
#include <stdint.h>

static void audio_callback(ma_device* device, void* Output, const void* Input, ma_uint32 frameCount);

bool AudioManager_Init();
bool AudioManager_Deinit();


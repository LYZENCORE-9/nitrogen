#pragma once

#include <miniaudio/miniaudio.h>

typedef struct AudioData
{
	ma_device_config deviceConfig;
	ma_decoder decoder;
	ma_device device;


} AudioData;

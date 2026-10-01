#pragma once
#include <stdbool.h>
#include <miniaudio/miniaudio.h>
#include <stdint.h>


bool AudioManager_Init();
void AudioManager_Deinit();

bool AudioManager_SwitchSoundFile(const char* filepath);

void AudioManager_CallPlay();
void AudioManager_CallPause();
void AudioManager_CallResume();
void AudioManager_CallStop(); // resets everything , i mean resets track data
bool AudioManager_IsPaused();
bool AudioManager_IsStopped();



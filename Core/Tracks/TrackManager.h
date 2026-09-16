#pragma once
#include <stdbool.h>
#include <stdint.h>

#include "TrackData.h"


bool TrackManager_Init();
bool TrackManager_Deinit();

bool TM_CreateTrack(Track track);
bool TM_DeleteTrack(Track track);
bool TM_EditTrack(uint32_t id, Track new_track_data);

bool TM_PlayTrack(uint32_t id);
bool TM_StopTrack();

Track* TM_GetTrackByName(const char* name);
Track* TM_GetTrackByID(uint32_t id);


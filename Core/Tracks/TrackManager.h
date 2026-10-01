#pragma once
#include <stdbool.h>
#include <stdint.h>

#include "TrackData.h"


bool TrackManager_Init();
bool TrackManager_Deinit();

bool TM_CreateTrack(Track track);
bool TM_DeleteTrack(Track track);
bool TM_EditTrack(uint32_t id, Track new_track_data);

bool TM_Select(uint32_t id);
bool TM_Unselect();

bool TM_Play();
bool TM_Stop();

Track* TM_GetTrackByName(const char* name);
Track* TM_GetTrackByID(uint32_t id);


#pragma once
#include <stdbool.h>
#include "Tracks/TrackData.h"

bool Database_Init(const char* filepath);
void Database_Deinit();

// Track
bool DB_TrackExists_i(uint32_t id);
bool DB_TrackExists_s(const char* track_name);

bool DB_InsertTrack(Track track);
bool DB_RemoveTrack(uint32_t id);
bool DB_UpdateTrack(uint32_t id, Track new_track_info);
bool DB_LoadTrack(uint32_t id, Track* temporary_track);








#pragma once

#include <stdint.h>

typedef enum FileType
{
	FILETYPE_MP3,
	FILETYPE_OGG
} FileType;

typedef enum TrackState
{
	PLAYING,
	CHOSEN,
	STOPPED
} TrackState;

typedef struct Track
{
	uint32_t id;
	char name[128];
	FileType filetype;

	char author[128];
} Track;


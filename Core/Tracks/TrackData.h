#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum TrackState
{
	PLAYING,
	CHOSEN,
	STOPPED
} TrackState;


typedef enum {
    AUDIO_FORMAT_UNKNOWN = 0,
    AUDIO_FORMAT_MP3,
    AUDIO_FORMAT_FLAC,
    AUDIO_FORMAT_WAV,
    AUDIO_FORMAT_OGG,
    AUDIO_FORMAT_AAC,
    AUDIO_FORMAT_M4A
} FileType;

typedef struct Track
{
	uint32_t id;	

	FileType filetype;
	
	//char filepath[1024];
	
	char title[256];
	char artist[128];
	char album[128];
	char genre[64];
	uint16_t year;
	uint16_t track_number; // idk related to order number in Album
	

	// 4. Audio Stream Properties
	uint32_t duration_sec;      // Total duration in seconds
	uint32_t sample_rate;       // e.g., 44100, 48000, 96000 Hz
	uint32_t bitrate;           // In kbps (e.g., 320, 1411)
	uint8_t channels;           // 1 = Mono, 2 = Stereo, 6 = 5.1 Surround

	// 5. User & DB Flags
	bool is_liked;              // User favorite status
	int64_t file_size_bytes;    // File size for change validation
	


} Track;


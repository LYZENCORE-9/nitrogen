#pragma once
#include "sqlite3/sqlite3.h"
#include "Audio/AudioData.h"
#include <pthread.h>

typedef struct GlobalContext
{
	// directories
	char tracks_directory[128];
	char database_directory[128];
	
	// Database 
	sqlite3* database;

	// Audio 
	AudioData AudioContext;

	//Threads
	pthread_t decoder_thread_handle;
	atomic_bool decoder_thread_isRunning;


} GlobalContext;

extern GlobalContext GlobalContextCore;

#pragma once
#include "sqlite3/sqlite3.h"

typedef struct GlobalContext
{
	// directories
	char tracks_directory[128];
	char database_directory[128];
	
	// Database 
	sqlite3* database;


} GlobalContext;

extern GlobalContext GlobalContextCore;

#include "GlobalContext.h"
#include "Database.h"
#include "rxi-log/log.h"

bool Database_init(const char* filepath)
{
	int ec = sqlite3_open(filepath, &GlobalContextCore.database);
	if(ec != SQLITE_OK)
	{
		log_fatal("SQLite Database failed to initialize.");
		sqlite3_close(GlobalContextCore.database);
		return false;
	}
	log_info("SQLite Database has initialized successfully");
	log_debug("SQLite DB (%s) .", GlobalContextCore.database_directory);
	return true;
}

void Database_Deinit()
{
	sqlite3_close(GlobalContextCore.database);
	log_info("SQLite Database has been deinitialized successfully.");
	log_debug("SQLite DB (%s) .", GlobalContextCore.database_directory);
}

#include "Database.h"
#include "sqlite3/sqlite3.h"

bool DB_TrackExists_i(uint32_t id)
{
	sqlite3_stmt* stmt;
	const char* zSql = "SELECT name FROM Tracks WHERE id = ?;";

	bool exists = false;

	sqlite3_bind_int(stmt, 0, id);
	if(sqlite3_step(stmt) == SQLITE_ROW)
		exists = true;

	sqlite3_finalize(stmt);
	return exists;
}

bool DB_TrackExists_s(const char *track_name)
{
	sqlite3_stmt* stmt;
	const char* zSql = "SELECT id FROM Tracks WHERE name=?;";

	bool exists = false;

	sqlite3_bind_text(stmt, 0, track_name, -1, SQLITE_TRANSIENT);
	if(sqlite3_step(stmt) == SQLITE_ROW)
		exists = true;

	sqlite3_finalize(stmt);
	return exists;
}


bool DB_InsertTrack(Track track)
{
}

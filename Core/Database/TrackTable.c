#include "Database.h"
#include "sqlite3/sqlite3.h"
#include "Tracks/TrackData.h"
#include <stdint.h>
#include "rxi-log/log.h"
#include <stdlib.h>
#include <string.h>

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
	if(DB_TrackExists_s(track.title) == true)
		return false;

	sqlite3_stmt* stmt;
	const char* zSql = "INSERT INTO Tracks(filetype, title, artist, album, genre) VALUES (?,?,?,?,?);";

	sqlite3_bind_int(stmt, 0, (int)track.filetype);
	sqlite3_bind_text(stmt, 1, track.title, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, track.artist, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, track.album, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, track.genre, -1, SQLITE_TRANSIENT);

	if(sqlite3_step(stmt) != SQLITE_DONE)
	{
		log_error("Error has been occured while inserting a Track row in Table .");
		return false;
	}
	sqlite3_finalize(stmt);
	log_info("Track row has been inserted successfuly (Track : %s)", track.title);
	return true;
}

bool DB_UpdateTrack(uint32_t id, Track new_track_info)
{
	if(DB_TrackExists_i(id) == false)
		return false;

	sqlite3_stmt *stmt;
	const char* zSql = "UPDATE Tracks SET filetype=?,title=?,artist=?,album=?,genre=? WHERE id=?;";
	
	sqlite3_bind_int(stmt, 0, (int)new_track_info.filetype);
	sqlite3_bind_text(stmt, 1, new_track_info.title, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, new_track_info.artist, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, new_track_info.album, -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, new_track_info.genre, -1, SQLITE_TRANSIENT);

	bool success = (sqlite3_step(stmt) == SQLITE_DONE);
	return success;

}

bool DB_LoadTrack(uint32_t id, Track* temporary_track)
{
	if(DB_TrackExists_i(id) == false)
		return false;


	sqlite3_stmt* stmt;
	const char* zSql = "SELECT filetype,title,artist,album,genre WHERE id=?;";
	
	sqlite3_bind_int(stmt, 0, id);
	
	if(sqlite3_step(stmt) != SQLITE_ROW)
		return false;

	int filetype = sqlite3_column_int(stmt, 1);
	char* title = (char*)sqlite3_column_text(stmt, 2);
	char* artist = (char*)sqlite3_column_text(stmt, 3);
	char* album = (char*)sqlite3_column_text(stmt, 4);
	char* genre = (char*)sqlite3_column_text(stmt, 5);

	temporary_track->filetype = filetype;
	memcpy(temporary_track->title, title, sizeof(temporary_track->title));
	memcpy(temporary_track->artist, artist, sizeof(temporary_track->artist));
	memcpy(temporary_track->album, album, sizeof(temporary_track->album));
	memcpy(temporary_track->genre, genre, sizeof(temporary_track->genre));
	log_info("* Track ID:%d has been loaded from Database .", id);
	return true;
}

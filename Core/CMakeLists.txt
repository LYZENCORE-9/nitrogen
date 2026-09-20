cmake_minimum_required(VERSION 4.0)
project(LLCore LANGUAGES C CXX)

set(SRC_LIST "")
list(APPEND SRC_LIST
	"Database/Database.c"

	"Tracks/TrackManager.c"

	"GlobalContext.c"
)

add_library(LLCore SHARED ${SRC_LIST})
target_include_directories(LLCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(LLCore PUBLIC sqlite3 mongoose rxi-log miniaudio)

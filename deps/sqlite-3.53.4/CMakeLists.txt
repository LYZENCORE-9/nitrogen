cmake_minimum_required(VERSION 4.0)
project(sqlite3 LANGUAGES C CXX)

set(SRC "sqlite3.c")

add_library(sqlite3 STATIC ${SRC})
target_include_directories(sqlite3 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_options(sqlite3 PUBLIC -fpic)

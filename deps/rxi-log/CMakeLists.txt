project(rxi-log LANGUAGES C CXX)

add_library(rxi-log STATIC "src/log.c")
target_include_directories(rxi-log PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

cmake_minimum_required(VERSION 4.0)
project(mongoose)

set(SRC "mongoose.c")

add_library(mongoose STATIC ${SRC})

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

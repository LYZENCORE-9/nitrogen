cmake_minimum_required(VERSION 4.0)
project(nitrogen LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# deps
add_subdirectory(deps)

# Core LL
add_subdirectory(Core)

# Client CL (replacable)
#add_subdirectory(Client)

#test
add_subdirectory(test)

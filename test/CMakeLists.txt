project(test LANGUAGES C CXX)

add_executable(test "main.c")
target_link_libraries(test PUBLIC LLCore)
target_include_directories(test PUBLIC LLCore)

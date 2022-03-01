cmake_minimum_required(VERSION 3.20)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled4 main.c)

add_library(str string/string_.h string/string_.c)
add_subdirectory(libs)
target_link_libraries(untitled4 str)
target_link_libraries(untitled4 data_structures)
target_link_libraries(untitled4 algorithms)
cmake_minimum_required (VERSION 2.8) 
project (main)
set (CMAKE_CXX_STANDARD 11)

include_directories (src/)
add_executable (main src/main.cpp src/i2c.cpp src/thunderborg.cpp)
target_link_libraries (main)

cmake_minimum_required (VERSION 2.6)
project (morse)
add_executable(morse morse.cpp)
SET(CMAKE_CXX_FLAGS "-g -O0 -std=c++11")

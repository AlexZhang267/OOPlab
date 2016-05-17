cmake_minimum_required(VERSION 3.4.3)
project(lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES lab3.cpp Preprocessor.cpp Preprocessor.h)
add_executable(lab3 ${SOURCE_FILES})
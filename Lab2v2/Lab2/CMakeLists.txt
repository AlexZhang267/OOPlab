cmake_minimum_required(VERSION 3.4)
project(Lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Commodity.h FamilyMart.h FamilyMart.cpp Customer.h Customer.cpp)
add_executable(Lab2 ${SOURCE_FILES})
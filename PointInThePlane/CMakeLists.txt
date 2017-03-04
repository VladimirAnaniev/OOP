cmake_minimum_required(VERSION 3.6)
project(PointInThePlane)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp PointInThePlane.cpp PointInThePlane.h)
add_executable(PointInThePlane ${SOURCE_FILES})
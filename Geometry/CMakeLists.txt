cmake_minimum_required(VERSION 3.6)
project(PointInThePlane)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp PointInThePlane.cpp PointInThePlane.h PointInSpace.cpp PointInSpace.h)
add_executable(PointInThePlane ${SOURCE_FILES})
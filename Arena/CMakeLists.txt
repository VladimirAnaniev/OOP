cmake_minimum_required(VERSION 3.6)
project(Arena)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Classes/Monster.cpp Classes/Monster.h)
add_executable(Arena ${SOURCE_FILES})
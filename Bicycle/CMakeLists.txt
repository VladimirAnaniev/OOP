cmake_minimum_required(VERSION 3.6)
project(Bycicle)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CyclePart.cpp CyclePart.h Quality.h Bicycle.cpp Bicycle.h)
add_executable(Bycicle ${SOURCE_FILES})
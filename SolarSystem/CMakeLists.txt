cmake_minimum_required(VERSION 3.6)
project(SolarSystem)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Planet.cpp Planet.h SolarSystem.cpp SolarSystem.h)
add_executable(SolarSystem ${SOURCE_FILES})
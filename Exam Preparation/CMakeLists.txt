cmake_minimum_required(VERSION 3.7)
project(Exam_Preparation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Necklace/Necklace.cpp Necklace/Necklace.h)
add_executable(Exam_Preparation ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.6)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ComplexNumber.cpp ComplexNumber.h)
add_executable(ComplexNumbers ${SOURCE_FILES})
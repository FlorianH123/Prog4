cmake_minimum_required(VERSION 3.8)
project(Uebung1)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES studentStruct.h bubbleSort.cpp main.cpp)
add_executable(Uebung1 ${SOURCE_FILES})
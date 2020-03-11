cmake_minimum_required(VERSION 3.5)

project(test-ppm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test-ppm ppm.h ppm.cpp main.cpp)

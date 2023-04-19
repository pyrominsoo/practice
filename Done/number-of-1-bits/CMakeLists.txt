cmake_minimum_required(VERSION 3.16)

project(
    practice
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

add_executable(
    prog
    src/main.cpp
)


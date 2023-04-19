cmake_minimum_required(VERSION 3.16)

project(
    Hello
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(
    hello
    src/main.cpp
    )

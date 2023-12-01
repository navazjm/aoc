# CMake minimum version required
cmake_minimum_required(VERSION 3.12)

# Project name
project(AOC_2023)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/day_01/day_01.cpp
    src/day_01/day_01.h
)

# Header files
set(HEADERS
    include/aoc.h
)

# Add executable target
add_executable(aoc_2023 ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(aoc_2023 PRIVATE include)

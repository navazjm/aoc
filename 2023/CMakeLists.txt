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
    src/day_02/day_02.cpp
    src/day_03/day_03.cpp
    src/day_04/day_04.cpp
	src/day_05/day_05.cpp
    include/aoc.cpp
)

# Header files
include_directories(include)

# Exclude the template folder
list(APPEND EXCLUDED_FOLDERS "template")
foreach(EXCLUDED_FOLDER ${EXCLUDED_FOLDERS})
    file(GLOB EXCLUDED_FILES "${CMAKE_SOURCE_DIR}/${EXCLUDED_FOLDER}/*")
    list(REMOVE_ITEM SOURCES ${EXCLUDED_FILES})
endforeach()

# Add executable target
add_executable(aoc_2023 ${SOURCES})

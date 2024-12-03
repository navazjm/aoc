# CMake minimum version required
cmake_minimum_required(VERSION 3.12)

# Project name
project(aoc)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/aoc.cpp
    src/day_01/day_01.cpp
)

# Exclude the template folder
list(APPEND EXCLUDED_FOLDERS "template")
foreach(EXCLUDED_FOLDER ${EXCLUDED_FOLDERS})
    file(GLOB EXCLUDED_FILES "${CMAKE_SOURCE_DIR}/${EXCLUDED_FOLDER}/*")
    list(REMOVE_ITEM SOURCES ${EXCLUDED_FILES})
endforeach()

# Add executable target
add_executable(aoc ${SOURCES})

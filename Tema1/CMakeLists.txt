cmake_minimum_required(VERSION 3.10)
project(tema1)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(FARA_DESTRUCTOR "" OFF)
option(SHALLOW_COPY "" OFF)
option(FARA_MOVE "" OFF)
if(FARA_DESTRUCTOR)
    add_definitions(-DFARA_DESTRUCTOR)
endif()
if(SHALLOW_COPY)
    add_definitions(-DSHALLOW_COPY)
endif()
if(FARA_MOVE)
    add_definitions(-DFARA_MOVE)
endif()

add_executable(${PROJECT_NAME}
    inc/tema1/playlist.hpp
    src/main.cpp
    src/playlist.cpp
)

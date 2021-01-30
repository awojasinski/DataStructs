cmake_minimum_required(VERSION 3.1)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -g")
set(CMAKE_C_FLAGS "-Wall -g")

project(DataStructures)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc/
    )

file(GLOB SRCS
    "${PROJECT_SOURCE_DIR}/src/*.c",
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SRCS})
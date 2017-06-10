cmake_minimum_required(VERSION 3.7)
project(vkCookBook)

set(CMAKE_CXX_STANDARD 11)

include_directories(Include)

set(SOURCE_FILES main.cpp)
add_executable(vkCookBook ${SOURCE_FILES})
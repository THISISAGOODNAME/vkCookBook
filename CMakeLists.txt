cmake_minimum_required(VERSION 3.7)
project(vkCookBook)

set(CMAKE_CXX_STANDARD 11)

include_directories(Include)

# Enabling validation layers
if(NOT DEFINED ENV{VK_INSTANCE_LAYERS})
    set( ENV{VK_INSTANCE_LAYERS} VK_LAYER_LUNARG_standard_validation )
endif()

set(SOURCE_FILES main.cpp)
add_executable(vkCookBook ${SOURCE_FILES})
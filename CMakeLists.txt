cmake_minimum_required(VERSION 3.7)
project(vkCookBook)

set(CMAKE_CXX_STANDARD 11)

include_directories(Include)

# Enabling validation layers
if(NOT DEFINED ENV{VK_INSTANCE_LAYERS})
    set( ENV{VK_INSTANCE_LAYERS} VK_LAYER_LUNARG_standard_validation )
endif()

set(COMMON_FILES book/common/ListOfVulkanFunctions.inl book/common/VulkanFunctions.cpp book/common/VulkanFunctions.h)

set(CH01_INSTANCE_AND_DEVICES
        book/CH01/S03_Connecting_with_a_Vulkan_Loader_library.cpp book/CH01/S03_Connecting_with_a_Vulkan_Loader_library.h)

set(SOURCE_FILES
        ${COMMON_FILES}
        ${CH01_INSTANCE_AND_DEVICES})
add_executable(vkCookBook ${SOURCE_FILES})
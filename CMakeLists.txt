cmake_minimum_required(VERSION 3.7)
project(vkCookBook)

set(CMAKE_CXX_STANDARD 11)

include_directories(Include)

# Enabling validation layers
if(NOT DEFINED ENV{VK_INSTANCE_LAYERS})
    set( ENV{VK_INSTANCE_LAYERS} VK_LAYER_LUNARG_standard_validation )
endif()

include_directories(book/common)

set(COMMON_FILES
        book/common/ListOfVulkanFunctions.inl
        book/common/VulkanFunctions.cpp
        book/common/VulkanFunctions.h
        book/common/Common.cpp
        book/common/Common.h
        book/common/VulkanDestroyer.cpp
        book/common/VulkanDestroyer.h)

set(CH01_INSTANCE_AND_DEVICES
        book/CH01/S03_Connecting_with_a_Vulkan_Loader_library.cpp
        book/CH01/S03_Connecting_with_a_Vulkan_Loader_library.h
        book/CH01/S05_Loading_function_exported_from_a_Vulkan_Loader_library.cpp
        book/CH01/S05_Loading_function_exported_from_a_Vulkan_Loader_library.h
        book/CH01/S06_Loading_global_level_functions.cpp
        book/CH01/S06_Loading_global_level_functions.h
        book/CH01/S07_Checking_available_Instance_extensions.cpp
        book/CH01/S07_Checking_available_Instance_extensions.h
        book/CH01/S08_Creating_a_Vulkan_Instance.cpp
        book/CH01/S08_Creating_a_Vulkan_Instance.h
        book/CH01/S09_Loading_instance_level_functions.cpp
        book/CH01/S09_Loading_instance_level_functions.h
        book/CH01/S10_Enumerating_available_physical_devices.cpp
        book/CH01/S10_Enumerating_available_physical_devices.h
        book/CH01/S11_Checking_available_device_extensions.cpp
        book/CH01/S11_Checking_available_device_extensions.h
        book/CH01/S12_Getting_features_and_properties_of_a_physical_device.cpp
        book/CH01/S12_Getting_features_and_properties_of_a_physical_device.h
        book/CH01/S13_Checking_available_queue_families_and_their_properties.cpp
        book/CH01/S13_Checking_available_queue_families_and_their_properties.h
        book/CH01/S14_Selecting_index_of_a_queue_family_with_desired_capabilities.cpp
        book/CH01/S14_Selecting_index_of_a_queue_family_with_desired_capabilities.h
        book/CH01/S15_Creating_a_logical_device.cpp
        book/CH01/S15_Creating_a_logical_device.h
        book/CH01/S16_Loading_device_level_functions.cpp
        book/CH01/S16_Loading_device_level_functions.h
        book/CH01/S17_Getting_a_device_queue.cpp
        book/CH01/S17_Getting_a_device_queue.h
        book/CH01/S18_Creating_a_logical_device_with_geometry_shaders_and_graphics_queue.cpp
        book/CH01/S18_Creating_a_logical_device_with_geometry_shaders_and_graphics_queue.h
        book/CH01/S19_Destroying_a_logical_device.cpp
        book/CH01/S19_Destroying_a_logical_device.h
        book/CH01/S20_Destroying_a_Vulkan_Instance.cpp
        book/CH01/S20_Destroying_a_Vulkan_Instance.h
        book/CH01/S21_Releasing_a_Vulkan_Loader_library.cpp
        book/CH01/S21_Releasing_a_Vulkan_Loader_library.h
        book/CH01/CH01_Instance_and_Devices.h)

set(CH02_IMAGE_PRESENTATION
        book/CH02/S01_Creating_a_Vulkan_Instance_with_WSI_extensions_enabled.cpp
        book/CH02/S01_Creating_a_Vulkan_Instance_with_WSI_extensions_enabled.h
        book/CH02/S02_Creating_a_presentation_surface.cpp
        book/CH02/S02_Creating_a_presentation_surface.h
        book/CH02/S03_Selecting_a_queue_family_that_supports_presentation_to_a_given_surface.cpp
        book/CH02/S03_Selecting_a_queue_family_that_supports_presentation_to_a_given_surface.h
        book/CH02/S04_Creating_a_logical_device_with_WSI_extensions_enabled.cpp
        book/CH02/S04_Creating_a_logical_device_with_WSI_extensions_enabled.h
        book/CH02/S05_Selecting_a_desired_presentation_mode.cpp
        book/CH02/S05_Selecting_a_desired_presentation_mode.h
        book/CH02/S06_Getting_capabilities_of_a_presentation_surface.cpp
        book/CH02/S06_Getting_capabilities_of_a_presentation_surface.h
        book/CH02/S07_Selecting_a_number_of_swapchain_images.cpp
        book/CH02/S07_Selecting_a_number_of_swapchain_images.h
        book/CH02/S08_Choosing_a_size_of_swapchain_images.cpp
        book/CH02/S08_Choosing_a_size_of_swapchain_images.h
        book/CH02/S09_Selecting_desired_usage_scenarios_of_swapchain_images.cpp
        book/CH02/S09_Selecting_desired_usage_scenarios_of_swapchain_images.h
        book/CH02/S10_Selecting_a_transformation_of_swapchain_images.cpp
        book/CH02/S10_Selecting_a_transformation_of_swapchain_images.h
        book/CH02/S11_Selecting_a_format_of_swapchain_images.cpp
        book/CH02/S11_Selecting_a_format_of_swapchain_images.h
        book/CH02/S12_Creating_a_swapchain.cpp
        book/CH02/S12_Creating_a_swapchain.h
        book/CH02/S13_Getting_handles_of_swapchain_images.cpp
        book/CH02/S13_Getting_handles_of_swapchain_images.h
        book/CH02/S14_Creating_a_swapchain_with_R8G8B8A8_format_and_a_MAILBOX_present_mode.cpp
        book/CH02/S14_Creating_a_swapchain_with_R8G8B8A8_format_and_a_MAILBOX_present_mode.h book/CH02/S15_Acquiring_a_swapchain_image.cpp book/CH02/S15_Acquiring_a_swapchain_image.h)

set(SOURCE_FILES
        ${COMMON_FILES}
        ${CH01_INSTANCE_AND_DEVICES}
        ${CH02_IMAGE_PRESENTATION})
add_executable(vkCookBook ${SOURCE_FILES})
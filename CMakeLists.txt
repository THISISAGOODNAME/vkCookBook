cmake_minimum_required(VERSION 3.7)
project(vkCookBook)

#set(CMAKE_CXX_STANDARD 11)

set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set( CMAKE_SUPPRESS_REGENERATION true )

if( CMAKE_BUILD_TYPE STREQUAL "" )
    set( CMAKE_BUILD_TYPE "debug" )
endif()

if( NOT DEFINED VK_USE_PLATFORM )
    if( WIN32 )
        set( VK_USE_PLATFORM "WIN32" )
    elseif( UNIX )
        set( VK_USE_PLATFORM "XCB" )
    endif()
endif()

add_definitions( -DVK_NO_PROTOTYPES )
add_definitions( -DVK_USE_PLATFORM_${VK_USE_PLATFORM}_KHR )

if( USE_PLATFORM STREQUAL "VK_USE_PLATFORM_WIN32_KHR" )
    set( CMAKE_C_FLAGS_RELWITHDEBINFO    "${CMAKE_C_FLAGS_RELWITHDEBINFO} /MT" )
    set( CMAKE_C_FLAGS_RELEASE           "${CMAKE_C_FLAGS_RELEASE} /MT" )
    set( CMAKE_C_FLAGS_DEBUG             "${CMAKE_C_FLAGS_DEBUG} /MTd" )
    set( CMAKE_CXX_FLAGS_RELWITHDEBINFO  "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /MT" )
    set( CMAKE_CXX_FLAGS_RELEASE         "${CMAKE_CXX_FLAGS_RELEASE} /MT" )
    set( CMAKE_CXX_FLAGS_DEBUG           "${CMAKE_CXX_FLAGS_DEBUG} /MTd" )
    set( PLATFORM_LIBRARY                "" )
elseif( USE_PLATFORM STREQUAL "VK_USE_PLATFORM_XCB_KHR" )
    add_definitions( -std=c++11 )
    set( PLATFORM_LIBRARY dl xcb )
elseif( USE_PLATFORM STREQUAL "VK_USE_PLATFORM_XLIB_KHR" )
    add_definitions( -std=c++11 )
    set( PLATFORM_LIBRARY dl X11 )
endif()

if( CMAKE_BUILD_TYPE STREQUAL "debug" )
    add_definitions(-D_DEBUG)
endif()

include_directories(Include/vulkan)

# Enabling validation layers
if(NOT DEFINED ENV{VK_INSTANCE_LAYERS})
    set( ENV{VK_INSTANCE_LAYERS} VK_LAYER_LUNARG_standard_validation )
endif()

include_directories(book/common)
include_directories(3rd_party/include)

set(COMMON_FILES
        book/common/ListOfVulkanFunctions.inl
        book/common/VulkanFunctions.cpp
        book/common/VulkanFunctions.h
        book/common/Common.cpp
        book/common/Common.h
        book/common/VulkanDestroyer.cpp
        book/common/VulkanDestroyer.h
        book/common/Tools.cpp
        book/common/Tools.h
        book/common/All_Lib.h)

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
        book/CH02/S14_Creating_a_swapchain_with_R8G8B8A8_format_and_a_MAILBOX_present_mode.h
        book/CH02/S15_Acquiring_a_swapchain_image.cpp
        book/CH02/S15_Acquiring_a_swapchain_image.h
        book/CH02/S16_Presenting_an_image.cpp
        book/CH02/S16_Presenting_an_image.h
        book/CH02/S17_Destroying_a_swapchain.cpp
        book/CH02/S17_Destroying_a_swapchain.h
        book/CH02/S18_Destroying_a_presentation_surface.cpp
        book/CH02/S18_Destroying_a_presentation_surface.h
        book/CH02/CH02_Image_Presentation.h)

set(CH03_COMMAND_BUFFERS_AND_SYNCHRONIZATION
        book/CH03/S01_Creating_a_command_pool.cpp
        book/CH03/S01_Creating_a_command_pool.h
        book/CH03/S02_Allocating_command_buffers.cpp
        book/CH03/S02_Allocating_command_buffers.h
        book/CH03/S03_Beginning_a_command_buffer_recording_operation.cpp
        book/CH03/S03_Beginning_a_command_buffer_recording_operation.h
        book/CH03/S04_Ending_a_command_buffer_recording_operation.cpp
        book/CH03/S04_Ending_a_command_buffer_recording_operation.h
        book/CH03/S05_Resetting_a_command_buffer.cpp
        book/CH03/S05_Resetting_a_command_buffer.h
        book/CH03/S06_Resetting_a_command_pool.cpp
        book/CH03/S06_Resetting_a_command_pool.h
        book/CH03/S07_Creating_a_semaphore.cpp
        book/CH03/S07_Creating_a_semaphore.h
        book/CH03/S08_Creating_a_fence.cpp
        book/CH03/S08_Creating_a_fence.h
        book/CH03/S09_Waiting_for_fences.cpp
        book/CH03/S09_Waiting_for_fences.h
        book/CH03/S10_Resetting_fences.cpp
        book/CH03/S10_Resetting_fences.h
        book/CH03/S11_Submitting_command_buffers_to_the_queue.cpp
        book/CH03/S11_Submitting_command_buffers_to_the_queue.h
        book/CH03/S12_Synchronizing_two_command_buffers.cpp
        book/CH03/S12_Synchronizing_two_command_buffers.h
        book/CH03/S13_Checking_if_processing_of_a_submitted_command_buffer_has_finished.cpp
        book/CH03/S13_Checking_if_processing_of_a_submitted_command_buffer_has_finished.h
        book/CH03/S14_Waiting_until_all_commands_submitted_to_a_queue_are_finished.cpp
        book/CH03/S14_Waiting_until_all_commands_submitted_to_a_queue_are_finished.h
        book/CH03/S15_Waiting_for_all_submitted_commands_to_be_finished.cpp
        book/CH03/S15_Waiting_for_all_submitted_commands_to_be_finished.h
        book/CH03/S16_Destroying_a_fence.cpp
        book/CH03/S16_Destroying_a_fence.h
        book/CH03/S17_Destroying_a_semaphore.cpp
        book/CH03/S17_Destroying_a_semaphore.h
        book/CH03/S18_Freeing_command_buffers.cpp
        book/CH03/S18_Freeing_command_buffers.h
        book/CH03/S19_Destroying_a_command_pool.cpp
        book/CH03/S19_Destroying_a_command_pool.h
        book/CH03/CH03_Command_Buffers_and_Synchronization.h)

set(CH04_RESOURCES_AND_MEMORY
        book/CH04/S01_Creating_a_buffer.cpp
        book/CH04/S01_Creating_a_buffer.h
        book/CH04/S02_Allocating_and_binding_memory_object_to_a_buffer.cpp
        book/CH04/S02_Allocating_and_binding_memory_object_to_a_buffer.h
        book/CH04/S03_Setting_a_buffer_memory_barrier.cpp
        book/CH04/S03_Setting_a_buffer_memory_barrier.h
        book/CH04/S04_Creating_a_buffer_view.cpp
        book/CH04/S04_Creating_a_buffer_view.h
        book/CH04/S05_Creating_an_image.cpp
        book/CH04/S05_Creating_an_image.h
        book/CH04/S06_Allocating_and_binding_memory_object_to_an_image.cpp
        book/CH04/S06_Allocating_and_binding_memory_object_to_an_image.h
        book/CH04/S07_Setting_an_image_memory_barrier.cpp
        book/CH04/S07_Setting_an_image_memory_barrier.h
        book/CH04/S08_Creating_an_image_view.cpp
        book/CH04/S08_Creating_an_image_view.h
        book/CH04/S09_Creating_a_2D_image_and_view.cpp
        book/CH04/S09_Creating_a_2D_image_and_view.h
        book/CH04/S10_Creating_a_layered_2D_image_with_a_CUBEMAP_view.cpp
        book/CH04/S10_Creating_a_layered_2D_image_with_a_CUBEMAP_view.h
        book/CH04/S11_Mapping_updating_and_unmapping_host_visible_memory.cpp
        book/CH04/S11_Mapping_updating_and_unmapping_host_visible_memory.h
        book/CH04/S12_Copying_data_between_buffers.cpp
        book/CH04/S12_Copying_data_between_buffers.h
        book/CH04/S13_Copying_data_from_a_buffer_to_an_image.cpp
        book/CH04/S13_Copying_data_from_a_buffer_to_an_image.h
        book/CH04/S14_Copying_data_from_an_image_to_a_buffer.cpp
        book/CH04/S14_Copying_data_from_an_image_to_a_buffer.h
        book/CH04/S15_Using_staging_buffer_to_update_a_buffer_with_a_device_local_memory_bound.cpp
        book/CH04/S15_Using_staging_buffer_to_update_a_buffer_with_a_device_local_memory_bound.h
        book/CH04/S20_Freeing_a_memory_object.cpp
        book/CH04/S20_Freeing_a_memory_object.h
        book/CH04/S21_Destroying_a_buffer.cpp
        book/CH04/S21_Destroying_a_buffer.h
        book/CH04/S16_Using_staging_buffer_to_update_an_image_with_a_device_local_memory_bound.cpp
        book/CH04/S16_Using_staging_buffer_to_update_an_image_with_a_device_local_memory_bound.h
        book/CH04/S17_Destroying_an_image_view.cpp
        book/CH04/S17_Destroying_an_image_view.h
        book/CH04/S18_Destroying_an_image.cpp
        book/CH04/S18_Destroying_an_image.h
        book/CH04/S19_Destroying_a_buffer_view.cpp
        book/CH04/S19_Destroying_a_buffer_view.h
        book/CH04/CH04_Resources_and_Memory.h)

set(CH05_DESCRIPTOR_SETS
        book/CH05/S01_Creating_a_sampler.cpp
        book/CH05/S01_Creating_a_sampler.h
        book/CH05/S02_Creating_a_sampled_image.cpp
        book/CH05/S02_Creating_a_sampled_image.h
        book/CH05/S03_Creating_a_combined_image_sampler.cpp
        book/CH05/S03_Creating_a_combined_image_sampler.h
        book/CH05/S04_Creating_a_storage_image.cpp
        book/CH05/S04_Creating_a_storage_image.h
        book/CH05/S05_Creating_a_uniform_texel_buffer.cpp
        book/CH05/S05_Creating_a_uniform_texel_buffer.h
        book/CH05/S06_Creating_a_storage_texel_buffer.cpp
        book/CH05/S06_Creating_a_storage_texel_buffer.h
        book/CH05/S07_Creating_a_uniform_buffer.cpp
        book/CH05/S07_Creating_a_uniform_buffer.h
        book/CH05/S08_Creating_a_storage_buffer.cpp
        book/CH05/S08_Creating_a_storage_buffer.h
        book/CH05/S09_Creating_an_input_attachment.cpp
        book/CH05/S09_Creating_an_input_attachment.h
        book/CH05/S10_Creating_a_descriptor_set_layout.cpp
        book/CH05/S10_Creating_a_descriptor_set_layout.h
        book/CH05/S11_Creating_a_descriptor_pool.cpp
        book/CH05/S11_Creating_a_descriptor_pool.h
        book/CH05/S12_Allocating_descriptor_sets.cpp
        book/CH05/S12_Allocating_descriptor_sets.h
        book/CH05/S13_Updating_descriptor_sets.cpp
        book/CH05/S13_Updating_descriptor_sets.h
        book/CH05/S14_Binding_descriptor_sets.cpp
        book/CH05/S14_Binding_descriptor_sets.h
        book/CH05/S15_Creating_descriptors_with_a_texture_and_a_uniform_buffer.cpp
        book/CH05/S15_Creating_descriptors_with_a_texture_and_a_uniform_buffer.h
        book/CH05/S16_Freeing_descriptor_sets.cpp
        book/CH05/S16_Freeing_descriptor_sets.h
        book/CH05/S17_Resetting_a_descriptor_pool.cpp
        book/CH05/S17_Resetting_a_descriptor_pool.h
        book/CH05/S18_Destroying_a_descriptor_pool.cpp
        book/CH05/S18_Destroying_a_descriptor_pool.h
        book/CH05/S19_Destroying_a_descriptor_set_layout.cpp
        book/CH05/S19_Destroying_a_descriptor_set_layout.h
        book/CH05/S20_Destroying_a_sampler.cpp
        book/CH05/S20_Destroying_a_sampler.h
        book/CH05/CH05_Descriptor_Sets.h)

set(CH06_RENDER_PASSES_AND_FRAMEBUFFERS
        book/CH06/S01_Specifying_attachments_descriptions.cpp
        book/CH06/S01_Specifying_attachments_descriptions.h
        book/CH06/S02_Specifying_subpass_descriptions.cpp
        book/CH06/S02_Specifying_subpass_descriptions.h
        book/CH06/S03_Specifying_dependencies_between_subpasses.cpp
        book/CH06/S03_Specifying_dependencies_between_subpasses.h
        book/CH06/S04_Creating_a_render_pass.cpp
        book/CH06/S04_Creating_a_render_pass.h
        book/CH06/S05_Creating_a_framebuffer.cpp
        book/CH06/S05_Creating_a_framebuffer.h
        book/CH06/S06_Preparing_a_render_pass_for_geometry_rendering_and_postprocess_subpasses.cpp
        book/CH06/S06_Preparing_a_render_pass_for_geometry_rendering_and_postprocess_subpasses.h
        book/CH06/S07_Preparing_a_render_pass_and_a_framebuffer_with_color_and_depth_attachments.cpp
        book/CH06/S07_Preparing_a_render_pass_and_a_framebuffer_with_color_and_depth_attachments.h
        book/CH06/S08_Beginning_a_render_pass.cpp
        book/CH06/S08_Beginning_a_render_pass.h
        book/CH06/S09_Progressing_to_the_next_subpass.cpp
        book/CH06/S09_Progressing_to_the_next_subpass.h
        book/CH06/S10_Ending_a_render_pass.cpp
        book/CH06/S10_Ending_a_render_pass.h
        book/CH06/S11_Destroying_a_framebuffer.cpp
        book/CH06/S11_Destroying_a_framebuffer.h
        book/CH06/S12_Destroying_a_render_pass.cpp
        book/CH06/S12_Destroying_a_render_pass.h
        book/CH06/CH06_Render_Passes_and_Framebuffers.h)

set(CH08_GRAPHICS_AND_COMPUTE_PIPELINES
        book/CH08/S01_Creating_a_shader_module.cpp
        book/CH08/S01_Creating_a_shader_module.h
        book/CH08/S02_Specifying_pipeline_shader_stages.cpp
        book/CH08/S02_Specifying_pipeline_shader_stages.h
        book/CH08/S03_Specifying_pipeline_vertex_input_state.cpp
        book/CH08/S03_Specifying_pipeline_vertex_input_state.h
        book/CH08/S04_Specifying_pipeline_input_assembly_state.cpp
        book/CH08/S04_Specifying_pipeline_input_assembly_state.h
        book/CH08/S05_Specifying_pipeline_tessellation_state.cpp
        book/CH08/S05_Specifying_pipeline_tessellation_state.h
        book/CH08/S06_Specifying_pipeline_viewport_and_scissor_test_state.cpp
        book/CH08/S06_Specifying_pipeline_viewport_and_scissor_test_state.h
        book/CH08/S07_Specifying_pipeline_rasterization_state.cpp
        book/CH08/S07_Specifying_pipeline_rasterization_state.h
        book/CH08/S08_Specifying_pipeline_multisample_state.cpp
        book/CH08/S08_Specifying_pipeline_multisample_state.h
        book/CH08/S09_Specifying_pipeline_depth_and_stencil_state.cpp
        book/CH08/S09_Specifying_pipeline_depth_and_stencil_state.h
        book/CH08/S10_Specifying_pipeline_blend_state.cpp
        book/CH08/S10_Specifying_pipeline_blend_state.h
        book/CH08/S11_Specifying_pipeline_dynamic_states.cpp
        book/CH08/S11_Specifying_pipeline_dynamic_states.h
        book/CH08/S12_Creating_a_pipeline_layout.cpp
        book/CH08/S12_Creating_a_pipeline_layout.h
        book/CH08/S13_Specifying_graphics_pipeline_creation_parameters.cpp
        book/CH08/S13_Specifying_graphics_pipeline_creation_parameters.h
        book/CH08/S14_Creating_a_pipeline_cache_object.cpp
        book/CH08/S14_Creating_a_pipeline_cache_object.h
        book/CH08/S15_Retrieving_data_from_a_pipeline_cache.cpp
        book/CH08/S15_Retrieving_data_from_a_pipeline_cache.h
        book/CH08/S16_Merging_multiple_pipeline_cache_objects.cpp
        book/CH08/S16_Merging_multiple_pipeline_cache_objects.h
        book/CH08/S17_Creating_graphics_pipelines.cpp
        book/CH08/S17_Creating_graphics_pipelines.h
        book/CH08/S18_Creating_a_compute_pipeline.cpp
        book/CH08/S18_Creating_a_compute_pipeline.h
        book/CH08/S19_Binding_a_pipeline_object.cpp
        book/CH08/S19_Binding_a_pipeline_object.h
        book/CH08/S20_Creating_a_pipeline_layout_with_a_combined_image_sampler_a_buffer_and_push_constant_ranges.cpp
        book/CH08/S20_Creating_a_pipeline_layout_with_a_combined_image_sampler_a_buffer_and_push_constant_ranges.h
        book/CH08/S21_Creating_pipeline_with_vertex_fragment_shaders_depth_test_enabled_with_dynamic_viewport_and_scissor_tests.cpp
        book/CH08/S21_Creating_pipeline_with_vertex_fragment_shaders_depth_test_enabled_with_dynamic_viewport_and_scissor_tests.h
        book/CH08/S22_Creating_multiple_graphics_pipelines_on_multiple_threads.cpp
        book/CH08/S22_Creating_multiple_graphics_pipelines_on_multiple_threads.h
        book/CH08/S23_Destroying_a_pipeline.cpp
        book/CH08/S23_Destroying_a_pipeline.h
        book/CH08/S24_Destroying_a_pipeline_cache.cpp
        book/CH08/S24_Destroying_a_pipeline_cache.h
        book/CH08/S25_Destroying_a_pipeline_layout.cpp
        book/CH08/S25_Destroying_a_pipeline_layout.h
        book/CH08/S26_Destroying_a_shader_module.cpp
        book/CH08/S26_Destroying_a_shader_module.h
        book/CH08/CH08_Graphics_and_Compute_Pipelines.h)

set(CH09_COMMAND_RECORDING_AND_DRAWING
        book/CH09/S01_Clearing_a_color_image.cpp
        book/CH09/S01_Clearing_a_color_image.h
        book/CH09/S02_Clearing_a_depth_stencil_image.cpp
        book/CH09/S02_Clearing_a_depth_stencil_image.h
        book/CH09/S03_Clearing_render_pass_attachments.cpp
        book/CH09/S03_Clearing_render_pass_attachments.h
        book/CH09/S04_Binding_vertex_buffers.cpp
        book/CH09/S04_Binding_vertex_buffers.h
        book/CH09/S05_Binding_an_index_buffer.cpp
        book/CH09/S05_Binding_an_index_buffer.h
        book/CH09/S06_Providing_data_to_shaders_through_push_constants.cpp
        book/CH09/S06_Providing_data_to_shaders_through_push_constants.h
        book/CH09/S07_Setting_viewport_state_dynamically.cpp
        book/CH09/S07_Setting_viewport_state_dynamically.h
        book/CH09/S08_Setting_scissor_state_dynamically.cpp
        book/CH09/S08_Setting_scissor_state_dynamically.h
        book/CH09/S09_Setting_line_width_state_dynamically.cpp
        book/CH09/S09_Setting_line_width_state_dynamically.h
        book/CH09/S10_Setting_depth_bias_state_dynamically.cpp
        book/CH09/S10_Setting_depth_bias_state_dynamically.h
        book/CH09/S11_Setting_blend_constants_state_dynamically.cpp
        book/CH09/S11_Setting_blend_constants_state_dynamically.h
        book/CH09/S12_Drawing_a_geometry.cpp
        book/CH09/S12_Drawing_a_geometry.h
        book/CH09/S13_Drawing_an_indexed_geometry.cpp
        book/CH09/S13_Drawing_an_indexed_geometry.h
        book/CH09/S14_Dispatching_compute_work.cpp
        book/CH09/S14_Dispatching_compute_work.h
        book/CH09/S15_Executing_secondary_command_buffer_inside_a_primary_command_buffer.cpp
        book/CH09/S15_Executing_secondary_command_buffer_inside_a_primary_command_buffer.h
        book/CH09/S16_Recording_a_command_buffer_that_draws_a_geometry_with_dynamic_viewport_and_scissor_states.cpp
        book/CH09/S16_Recording_a_command_buffer_that_draws_a_geometry_with_dynamic_viewport_and_scissor_states.h
        book/CH09/S17_Recording_command_buffers_on_multiple_threads.cpp
        book/CH09/S17_Recording_command_buffers_on_multiple_threads.h
        book/CH09/S18_Preparing_a_single_frame_of_animation.cpp
        book/CH09/S18_Preparing_a_single_frame_of_animation.h
        book/CH09/S19_Increasing_the_performance_through_increasing_the_number_of_separately_rendered_frames.cpp
        book/CH09/S19_Increasing_the_performance_through_increasing_the_number_of_separately_rendered_frames.h
        book/CH09/CH09_Command_Recording_and_Drawing.h)

set(CH10_HELPER_RECIPES
        book/CH10/S07_Loading_a_3D_model_from_an_OBJ_file.cpp
        book/CH10/S07_Loading_a_3D_model_from_an_OBJ_file.h
        book/CH10/S01_reparing_a_translation_matrix.cpp
        book/CH10/S01_reparing_a_translation_matrix.h
        book/CH10/S02_Preparing_a_rotation_matrix.cpp
        book/CH10/S02_Preparing_a_rotation_matrix.h
        book/CH10/S03_Preparing_a_scaling_matrix.cpp
        book/CH10/S03_Preparing_a_scaling_matrix.h
        book/CH10/S04_Preparing_a_perspective_projection_matrix.cpp
        book/CH10/S04_Preparing_a_perspective_projection_matrix.h
        book/CH10/S05_Preparing_an_orthographic_projection_matrix.cpp
        book/CH10/S05_Preparing_an_orthographic_projection_matrix.h
        book/CH10/S06_Loading_texture_data_from_a_file.cpp
        book/CH10/S06_Loading_texture_data_from_a_file.h
        book/CH10/CH10_Helper_Recipes.h)

set(LIB_FILES
        ${COMMON_FILES}
        ${CH01_INSTANCE_AND_DEVICES}
        ${CH02_IMAGE_PRESENTATION}
        ${CH03_COMMAND_BUFFERS_AND_SYNCHRONIZATION}
        ${CH04_RESOURCES_AND_MEMORY}
        ${CH05_DESCRIPTOR_SETS}
        ${CH06_RENDER_PASSES_AND_FRAMEBUFFERS}
        ${CH08_GRAPHICS_AND_COMPUTE_PIPELINES}
        ${CH09_COMMAND_RECORDING_AND_DRAWING}
        ${CH10_HELPER_RECIPES})

set(COMMON_FILES
        Samples/Common/Camera.cpp
        Samples/Common/Camera.h
        Samples/Common/OrbitingCamera.cpp
        Samples/Common/OrbitingCamera.h
        Samples/Common/CookbookSampleFramework.cpp
        Samples/Common/CookbookSampleFramework.h
        Samples/Common/OS.cpp
        Samples/Common/OS.h)

include_directories(Samples/Common)

# Shared Library
add_library( CookbookLibrary ${LIB_FILES} )
target_link_libraries( CookbookLibrary ${PLATFORM_LIBRARY} )

##
# Samples
#

# Step01-Creating_Logical_Device
add_executable( Step01-Creating_Logical_Device Samples/Step01-Creating_Logical_Device.cpp ${COMMON_FILES})
target_link_libraries( Step01-Creating_Logical_Device ${PLATFORM_LIBRARY} CookbookLibrary )

# Step02-Creating_Swapchain
add_executable( Step02-Creating_Swapchain Samples/Step02-Creating_Swapchain.cpp ${COMMON_FILES})
target_link_libraries( Step02-Creating_Swapchain ${PLATFORM_LIBRARY} CookbookLibrary )

# Step03-Using_Render_Passes
add_executable( Step03-Using_Render_Passes ${COMMON_FILES} Samples/Step03-Using_Render_Passes.cpp)
target_link_libraries( Step03-Using_Render_Passes ${PLATFORM_LIBRARY} CookbookLibrary )

# Step04-Using_Graphics_Pipeline
add_executable( Step04-Using_Graphics_Pipeline ${COMMON_FILES} Samples/Step04-Using_Graphics_Pipeline.cpp)
target_link_libraries( Step04-Using_Graphics_Pipeline ${PLATFORM_LIBRARY} CookbookLibrary )

# Step05-Using_Combined_Image_Samplers
add_executable( Step05-Using_Combined_Image_Samplers ${COMMON_FILES} Samples/Step05-Using_Combined_Image_Samplers.cpp)
target_link_libraries( Step05-Using_Combined_Image_Samplers ${PLATFORM_LIBRARY} CookbookLibrary )

# Step06-Using_Uniform_Buffers
add_executable( Step06-Using_Uniform_Buffers ${COMMON_FILES} Samples/Step06-Using_Uniform_Buffers.cpp)
target_link_libraries( Step06-Using_Uniform_Buffers ${PLATFORM_LIBRARY} CookbookLibrary )

# Step07-Using_Push_Constants
add_executable( Step07-Using_Push_Constants ${COMMON_FILES} Samples/Step07-Using_Push_Constants.cpp)
target_link_libraries( Step07-Using_Push_Constants ${PLATFORM_LIBRARY} CookbookLibrary )

# Step08-Using_Tessellation_Shaders
add_executable( Step08-Using_Tessellation_Shaders ${COMMON_FILES} Samples/Step08-Using_Tessellation_Shaders.cpp)
target_link_libraries( Step08-Using_Tessellation_Shaders ${PLATFORM_LIBRARY} CookbookLibrary )

# Step09-Using_Geometry_Shaders
add_executable( Step09-Using_Geometry_Shaders ${COMMON_FILES} Samples/Step09-Using_Geometry_Shaders.cpp)
target_link_libraries( Step09-Using_Geometry_Shaders ${PLATFORM_LIBRARY} CookbookLibrary )

# Step10-Using_Compute_Shaders
add_executable( Step10-Using_Compute_Shaders ${COMMON_FILES} Samples/Step10-Using_Compute_Shaders.cpp)
target_link_libraries( Step10-Using_Compute_Shaders ${PLATFORM_LIBRARY} CookbookLibrary )

# Step11-Drawing_Vertex_Normals
add_executable( Step11-Drawing_Vertex_Normals ${COMMON_FILES} Samples/Step11-Drawing_Vertex_Normals.cpp)
target_link_libraries( Step11-Drawing_Vertex_Normals ${PLATFORM_LIBRARY} CookbookLibrary )

# Step12-Using_Depth_Attachments
add_executable( Step12-Using_Depth_Attachments ${COMMON_FILES} Samples/Step12-Using_Depth_Attachments.cpp)
target_link_libraries( Step12-Using_Depth_Attachments ${PLATFORM_LIBRARY} CookbookLibrary )

# CH11 Lighting
# 01-Rendering_a_geometry_with_vertex_diffuse_lighting
add_executable( CH1101-Rendering_a_geometry_with_vertex_diffuse_lighting ${COMMON_FILES} Samples/CH11/S01-Rendering_a_geometry_with_vertex_diffuse_lighting.cpp)
target_link_libraries( CH1101-Rendering_a_geometry_with_vertex_diffuse_lighting ${PLATFORM_LIBRARY} CookbookLibrary )

# 02-Rendering_a_geometry_with_fragment_specular_lighting
add_executable( CH1102-Rendering_a_geometry_with_fragment_specular_lighting ${COMMON_FILES} Samples/CH11/S02-Rendering_a_geometry_with_fragment_specular_lighting.cpp)
target_link_libraries( CH1102-Rendering_a_geometry_with_fragment_specular_lighting ${PLATFORM_LIBRARY} CookbookLibrary )

# 03-Rendering_a_normal_mapped_geometry
add_executable( CH1103-Rendering_a_normal_mapped_geometry ${COMMON_FILES} Samples/CH11/S03-Rendering_a_normal_mapped_geometry.cpp)
target_link_libraries( CH1103-Rendering_a_normal_mapped_geometry ${PLATFORM_LIBRARY} CookbookLibrary )

# 04-Rendering_a_reflective_and_refractive_geometry_using_cubemaps
add_executable( CH1104-Rendering_a_reflective_and_refractive_geometry_using_cubemaps ${COMMON_FILES} Samples/CH11/S04-Rendering_a_reflective_and_refractive_geometry_using_cubemaps.cpp)
target_link_libraries( CH1104-Rendering_a_reflective_and_refractive_geometry_using_cubemaps ${PLATFORM_LIBRARY} CookbookLibrary )

# 05-Adding_shadows_to_the_scene
add_executable( CH1105-Adding_shadows_to_the_scene ${COMMON_FILES} Samples/CH11/S05-Adding_shadows_to_the_scene.cpp)
target_link_libraries( CH1105-Adding_shadows_to_the_scene ${PLATFORM_LIBRARY} CookbookLibrary )

# CH12 Advanced Rendering Techniques
# 01-Drawing_a_skybox
add_executable( CH1201-Drawing_a_skybox ${COMMON_FILES} Samples/CH12/S01-Drawing_a_skybox.cpp)
target_link_libraries( CH1201-Drawing_a_skybox ${PLATFORM_LIBRARY} CookbookLibrary )

# 02-Drawing_bilboards_using_geometry_shaders
add_executable( CH1202-Drawing_bilboards_using_geometry_shaders ${COMMON_FILES} Samples/CH12/S02-Drawing_bilboards_using_geometry_shaders.cpp)
target_link_libraries( CH1202-Drawing_bilboards_using_geometry_shaders ${PLATFORM_LIBRARY} CookbookLibrary )

# 03-Drawing_particles_using_compute_and_graphics_pipelines
add_executable( CH1203-Drawing_particles_using_compute_and_graphics_pipelines ${COMMON_FILES} Samples/CH12/S03-Drawing_particles_using_compute_and_graphics_pipelines.cpp)
target_link_libraries( CH1203-Drawing_particles_using_compute_and_graphics_pipelines ${PLATFORM_LIBRARY} CookbookLibrary )

# 04-Rendering_a_tesselated_terrain
add_executable( CH1204-Rendering_a_tesselated_terrain ${COMMON_FILES} Samples/CH12/S04-Rendering_a_tesselated_terrain.cpp)
target_link_libraries( CH1204-Rendering_a_tesselated_terrain ${PLATFORM_LIBRARY} CookbookLibrary )

# 05-Rendering_a_fullscreen_quad_for_postprocessing
add_executable( CH1205-Rendering_a_fullscreen_quad_for_postprocessing ${COMMON_FILES} Samples/CH12/S05-Rendering_a_fullscreen_quad_for_postprocessing.cpp)
target_link_libraries( CH1205-Rendering_a_fullscreen_quad_for_postprocessing ${PLATFORM_LIBRARY} CookbookLibrary )

# 06-Using_input_attachment_for_color_correction_postprocess_effect
add_executable( CH1206-Using_input_attachment_for_color_correction_postprocess_effect ${COMMON_FILES} Samples/CH12/S06-Using_input_attachment_for_color_correction_postprocess_effect.cpp)
target_link_libraries( CH1206-Using_input_attachment_for_color_correction_postprocess_effect ${PLATFORM_LIBRARY} CookbookLibrary )
//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  16 Recording a command buffer that draws a geometry with dynamic viewport and scissor states

#include "../CH03/S03_Beginning_a_command_buffer_recording_operation.h"
#include "../CH03/S04_Ending_a_command_buffer_recording_operation.h"
#include "../CH04/S07_Setting_an_image_memory_barrier.h"
#include "../CH05/S14_Binding_descriptor_sets.h"
#include "../CH06/S08_Beginning_a_render_pass.h"
#include "../CH06/S10_Ending_a_render_pass.h"
#include "../CH08/S19_Binding_a_pipeline_object.h"
#include "S07_Setting_viewport_state_dynamically.h"
#include "S08_Setting_scissor_state_dynamically.h"
#include "S12_Drawing_a_geometry.h"
#include "S16_Recording_a_command_buffer_that_draws_a_geometry_with_dynamic_viewport_and_scissor_states.h"

namespace VKCookbook {

    bool RecordCommandBufferThatDrawsGeometryWithDynamicViewportAndScissorStates( VkCommandBuffer                             command_buffer,
                                                                                  VkImage                                     swapchain_image,
                                                                                  uint32_t                                    present_queue_family_index,
                                                                                  uint32_t                                    graphics_queue_family_index,
                                                                                  VkRenderPass                                render_pass,
                                                                                  VkFramebuffer                               framebuffer,
                                                                                  VkExtent2D                                  framebuffer_size,
                                                                                  std::vector<VkClearValue> const &           clear_values,
                                                                                  VkPipeline                                  graphics_pipeline,
                                                                                  uint32_t                                    first_vertex_buffer_binding,
                                                                                  std::vector<VertexBufferParameters> const & vertex_buffers_parameters,
                                                                                  VkPipelineLayout                            pipeline_layout,
                                                                                  std::vector<VkDescriptorSet> const &        descriptor_sets,
                                                                                  uint32_t                                    index_for_first_descriptor_set,
                                                                                  Mesh const &                                geometry,
                                                                                  uint32_t                                    instance_count,
                                                                                  uint32_t                                    first_instance ){
        if( !BeginCommandBufferRecordingOperation( command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr ) ) {
            return false;
        }

        if( present_queue_family_index != graphics_queue_family_index ) {
            ImageTransition image_transition_before_drawing = {
                    swapchain_image,                          // VkImage              Image
                    VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        CurrentAccess
                    VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,     // VkAccessFlags        NewAccess
                    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        CurrentLayout
                    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        NewLayout
                    present_queue_family_index,               // uint32_t             CurrentQueueFamily
                    graphics_queue_family_index,              // uint32_t             NewQueueFamily
                    VK_IMAGE_ASPECT_COLOR_BIT                 // VkImageAspectFlags   Aspect
            };
            SetImageMemoryBarrier( command_buffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, { image_transition_before_drawing } );
        }

        BeginRenderPass( command_buffer, render_pass, framebuffer, { { 0, 0 }, framebuffer_size }, clear_values, VK_SUBPASS_CONTENTS_INLINE );

        BindPipelineObject( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphics_pipeline );

        VkViewport viewport = {
                0.0f,                                         // float          x
                0.0f,                                         // float          y
                static_cast<float>(framebuffer_size.width),   // float          width
                static_cast<float>(framebuffer_size.height),  // float          height
                0.0f,                                         // float          minDepth
                1.0f,                                         // float          maxDepth
        };
        SetViewportStateDynamically( command_buffer, 0, { viewport } );

        VkRect2D scissor = {
                {                                                     // VkOffset2D     offset
                        0,                                            // int32_t        x
                        0                                             // int32_t        y
                },
                {                                                     // VkExtent2D     extent
                        framebuffer_size.width,                       // uint32_t       width
                        framebuffer_size.height                       // uint32_t       height
                }
        };
        SetScissorStateDynamically( command_buffer, 0, { scissor } );

        BindVertexBuffers( command_buffer, first_vertex_buffer_binding, vertex_buffers_parameters );

        if( descriptor_sets.size() > 0 ) {
            BindDescriptorSets( command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_layout, index_for_first_descriptor_set, descriptor_sets, {} );
        }

        for( size_t i = 0; i < geometry.Parts.size(); ++i ) {
            DrawGeometry( command_buffer, geometry.Parts[i].VertexCount, instance_count, geometry.Parts[i].VertexOffset, first_instance );
        }

        EndRenderPass( command_buffer );

        if( present_queue_family_index != graphics_queue_family_index ) {
            ImageTransition image_transition_before_present = {
                    swapchain_image,                          // VkImage              Image
                    VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,     // VkAccessFlags        CurrentAccess
                    VK_ACCESS_MEMORY_READ_BIT,                // VkAccessFlags        NewAccess
                    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        CurrentLayout
                    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,          // VkImageLayout        NewLayout
                    graphics_queue_family_index,              // uint32_t             CurrentQueueFamily
                    present_queue_family_index,               // uint32_t             NewQueueFamily
                    VK_IMAGE_ASPECT_COLOR_BIT                 // VkImageAspectFlags   Aspect
            };
            SetImageMemoryBarrier( command_buffer, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, { image_transition_before_present } );
        }

        if( !EndCommandBufferRecordingOperation( command_buffer ) ) {
            return false;
        }
        return true;
    }

}
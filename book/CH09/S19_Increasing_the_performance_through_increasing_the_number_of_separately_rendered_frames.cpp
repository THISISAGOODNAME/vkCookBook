//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  19 Increasing the performance through increasing the number of separately rendered frames

#include "../CH03/S09_Waiting_for_fences.h"
#include "../CH03/S10_Resetting_fences.h"
#include "../CH06/S11_Destroying_a_framebuffer.h"
#include "S18_Preparing_a_single_frame_of_animation.h"
#include "S19_Increasing_the_performance_through_increasing_the_number_of_separately_rendered_frames.h"

namespace VKCookbook {

    bool IncreasePerformanceThroughIncreasingTheNumberOfSeparatelyRenderedFrames( VkDevice                                                        logical_device,
                                                                                  VkQueue                                                         graphics_queue,
                                                                                  VkQueue                                                         present_queue,
                                                                                  VkSwapchainKHR                                                  swapchain,
                                                                                  VkExtent2D                                                      swapchain_size,
                                                                                  std::vector<VkImageView> const                                & swapchain_image_views,
                                                                                  VkRenderPass                                                    render_pass,
                                                                                  std::vector<WaitSemaphoreInfo> const                          & wait_infos,
                                                                                  std::function<bool(VkCommandBuffer, uint32_t, VkFramebuffer)>   record_command_buffer,
                                                                                  std::vector<FrameResources>                                   & frame_resources ){
        static uint32_t frame_index = 0;
        FrameResources & current_frame = frame_resources[frame_index];

        if( !WaitForFences( logical_device, { *current_frame.DrawingFinishedFence }, false, 2000000000 ) ) {
            return false;
        }
        if( !ResetFences( logical_device, { *current_frame.DrawingFinishedFence } ) ) {
            return false;
        }

        InitVkDestroyer( logical_device, current_frame.Framebuffer );

        if( !PrepareSingleFrameOfAnimation( logical_device, graphics_queue, present_queue, swapchain, swapchain_size, swapchain_image_views,
                                            *current_frame.DepthAttachment, wait_infos, *current_frame.ImageAcquiredSemaphore, *current_frame.ReadyToPresentSemaphore,
                                            *current_frame.DrawingFinishedFence, record_command_buffer, current_frame.CommandBuffer, render_pass, current_frame.Framebuffer ) ) {
            return false;
        }

        frame_index = (frame_index + 1) % frame_resources.size();
        return true;
    }

}
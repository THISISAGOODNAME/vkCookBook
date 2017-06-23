//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  19 Increasing the performance through increasing the number of separately rendered frames

#ifndef VKCOOKBOOK_S19_INCREASING_THE_PERFORMANCE_THROUGH_INCREASING_THE_NUMBER_OF_SEPARATELY_RENDERED_FRAMES_H
#define VKCOOKBOOK_S19_INCREASING_THE_PERFORMANCE_THROUGH_INCREASING_THE_NUMBER_OF_SEPARATELY_RENDERED_FRAMES_H

#include "../CH03/S11_Submitting_command_buffers_to_the_queue.h"

namespace VKCookbook {

    struct FrameResources {
        VkCommandBuffer             CommandBuffer;
        VkDestroyer<VkSemaphore>    ImageAcquiredSemaphore;
        VkDestroyer<VkSemaphore>    ReadyToPresentSemaphore;
        VkDestroyer<VkFence>        DrawingFinishedFence;
        VkDestroyer<VkImageView>    DepthAttachment;
        VkDestroyer<VkFramebuffer>  Framebuffer;
    };

    bool IncreasePerformanceThroughIncreasingTheNumberOfSeparatelyRenderedFrames( VkDevice                                                        logical_device,
                                                                                  VkQueue                                                         graphics_queue,
                                                                                  VkQueue                                                         present_queue,
                                                                                  VkSwapchainKHR                                                  swapchain,
                                                                                  VkExtent2D                                                      swapchain_size,
                                                                                  std::vector<VkImageView> const                                & swapchain_image_views,
                                                                                  VkRenderPass                                                    render_pass,
                                                                                  std::vector<WaitSemaphoreInfo> const                          & wait_infos,
                                                                                  std::function<bool(VkCommandBuffer, uint32_t, VkFramebuffer)>   record_command_buffer,
                                                                                  std::vector<FrameResources>                                   & frame_resources );

};


#endif //VKCOOKBOOK_S19_INCREASING_THE_PERFORMANCE_THROUGH_INCREASING_THE_NUMBER_OF_SEPARATELY_RENDERED_FRAMES_H

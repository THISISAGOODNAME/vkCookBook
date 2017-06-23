//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  18 Preparing a single frame of animation

#ifndef VKCOOKBOOK_S18_PREPARING_A_SINGLE_FRAME_OF_ANIMATION_H
#define VKCOOKBOOK_S18_PREPARING_A_SINGLE_FRAME_OF_ANIMATION_H

#include "../CH03/S11_Submitting_command_buffers_to_the_queue.h"

namespace VKCookbook {

    bool PrepareSingleFrameOfAnimation( VkDevice                                                        logical_device,
                                        VkQueue                                                         graphics_queue,
                                        VkQueue                                                         present_queue,
                                        VkSwapchainKHR                                                  swapchain,
                                        VkExtent2D                                                      swapchain_size,
                                        std::vector<VkImageView> const                                & swapchain_image_views,
                                        VkImageView                                                     depth_attachment,
                                        std::vector<WaitSemaphoreInfo> const                          & wait_infos,
                                        VkSemaphore                                                     image_acquired_semaphore,
                                        VkSemaphore                                                     ready_to_present_semaphore,
                                        VkFence                                                         finished_drawing_fence,
                                        std::function<bool(VkCommandBuffer, uint32_t, VkFramebuffer)>   record_command_buffer,
                                        VkCommandBuffer                                                 command_buffer,
                                        VkRenderPass                                                    render_pass,
                                        VkDestroyer<VkFramebuffer>                                    & framebuffer );

};


#endif //VKCOOKBOOK_S18_PREPARING_A_SINGLE_FRAME_OF_ANIMATION_H

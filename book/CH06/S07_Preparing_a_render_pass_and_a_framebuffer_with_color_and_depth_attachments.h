//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  07 Preparing a render pass and a framebuffer with color and depth attachments

#ifndef VKCOOKBOOK_S07_PREPARING_A_RENDER_PASS_AND_A_FRAMEBUFFER_WITH_COLOR_AND_DEPTH_ATTACHMENTS_H
#define VKCOOKBOOK_S07_PREPARING_A_RENDER_PASS_AND_A_FRAMEBUFFER_WITH_COLOR_AND_DEPTH_ATTACHMENTS_H

#include "Common.h"

namespace VKCookbook {

    bool PrepareRenderPassAndFramebufferWithColorAndDepthAttachments( VkPhysicalDevice        physical_device,
                                                                      VkDevice                logical_device,
                                                                      uint32_t                width,
                                                                      uint32_t                height,
                                                                      VkImage               & color_image,
                                                                      VkDeviceMemory        & color_image_memory_object,
                                                                      VkImageView           & color_image_view,
                                                                      VkImage               & depth_image,
                                                                      VkDeviceMemory        & depth_image_memory_object,
                                                                      VkImageView           & depth_image_view,
                                                                      VkRenderPass          & render_pass,
                                                                      VkFramebuffer         & framebuffer );

};


#endif //VKCOOKBOOK_S07_PREPARING_A_RENDER_PASS_AND_A_FRAMEBUFFER_WITH_COLOR_AND_DEPTH_ATTACHMENTS_H

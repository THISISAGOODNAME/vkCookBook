//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  12 Creating a swapchain

#ifndef VKCOOKBOOK_S12_CREATING_A_SWAPCHAIN_H
#define VKCOOKBOOK_S12_CREATING_A_SWAPCHAIN_H

#include "Common.h"

namespace VKCookbook {

    bool CreateSwapchain( VkDevice                        logical_device,
                          VkSurfaceKHR                    presentation_surface,
                          uint32_t                        image_count,
                          VkSurfaceFormatKHR              surface_format,
                          VkExtent2D                      image_size,
                          VkImageUsageFlags               image_usage,
                          VkSurfaceTransformFlagBitsKHR   surface_transform,
                          VkPresentModeKHR                present_mode,
                          VkSwapchainKHR                & old_swapchain,
                          VkSwapchainKHR                & swapchain );

};


#endif //VKCOOKBOOK_S12_CREATING_A_SWAPCHAIN_H

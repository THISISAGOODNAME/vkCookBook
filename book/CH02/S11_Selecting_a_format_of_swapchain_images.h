//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  11 Selecting a format of swapchain images

#ifndef VKCOOKBOOK_S11_SELECTING_A_FORMAT_OF_SWAPCHAIN_IMAGES_H
#define VKCOOKBOOK_S11_SELECTING_A_FORMAT_OF_SWAPCHAIN_IMAGES_H

#include "Common.h"

namespace VKCookbook {

    bool SelectFormatOfSwapchainImages( VkPhysicalDevice     physical_device,
                                        VkSurfaceKHR         presentation_surface,
                                        VkSurfaceFormatKHR   desired_surface_format,
                                        VkFormat           & image_format,
                                        VkColorSpaceKHR    & image_color_space );

};


#endif //VKCOOKBOOK_S11_SELECTING_A_FORMAT_OF_SWAPCHAIN_IMAGES_H

//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  13 Getting handles of swapchain images

#ifndef VKCOOKBOOK_S13_GETTING_HANDLES_OF_SWAPCHAIN_IMAGES_H
#define VKCOOKBOOK_S13_GETTING_HANDLES_OF_SWAPCHAIN_IMAGES_H

#include "Common.h"

namespace VKCookbook {

    bool GetHandlesOfSwapchainImages( VkDevice               logical_device,
                                      VkSwapchainKHR         swapchain,
                                      std::vector<VkImage> & swapchain_images );

};


#endif //VKCOOKBOOK_S13_GETTING_HANDLES_OF_SWAPCHAIN_IMAGES_H

//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  17 Destroying a swapchain

#ifndef VKCOOKBOOK_S17_DESTROYING_A_SWAPCHAIN_H
#define VKCOOKBOOK_S17_DESTROYING_A_SWAPCHAIN_H

#include "Common.h"

namespace VKCookbook {

    void DestroySwapchain( VkDevice         logical_device,
                           VkSwapchainKHR & swapchain );

};


#endif //VKCOOKBOOK_S17_DESTROYING_A_SWAPCHAIN_H

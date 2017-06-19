//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  15 Acquiring a swapchain image

#ifndef VKCOOKBOOK_S15_ACQUIRING_A_SWAPCHAIN_IMAGE_H
#define VKCOOKBOOK_S15_ACQUIRING_A_SWAPCHAIN_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    bool AcquireSwapchainImage( VkDevice         logical_device,
                                VkSwapchainKHR   swapchain,
                                VkSemaphore      semaphore,
                                VkFence          fence,
                                uint32_t       & image_index );

};


#endif //VKCOOKBOOK_S15_ACQUIRING_A_SWAPCHAIN_IMAGE_H

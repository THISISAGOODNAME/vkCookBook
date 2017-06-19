//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  15 Acquiring a swapchain image

#include "S15_Acquiring_a_swapchain_image.h"

namespace VKCookbook {

    bool AcquireSwapchainImage( VkDevice         logical_device,
                                VkSwapchainKHR   swapchain,
                                VkSemaphore      semaphore,
                                VkFence          fence,
                                uint32_t       & image_index ) {
        VkResult result;

        result = vkAcquireNextImageKHR( logical_device, swapchain, 2000000000, semaphore, fence, &image_index );
        switch( result ) {
            case VK_SUCCESS:
            case VK_SUBOPTIMAL_KHR:
                return true;
            default:
                return false;
        }
    }

}
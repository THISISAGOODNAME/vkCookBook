//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  17 Destroying a swapchain

#include "S17_Destroying_a_swapchain.h"

namespace VKCookbook {

    void DestroySwapchain( VkDevice         logical_device,
                           VkSwapchainKHR & swapchain ) {
        if ( swapchain ) {
            vkDestroySwapchainKHR( logical_device, swapchain, nullptr );
            swapchain = VK_NULL_HANDLE;
        }
    }

}
//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  13 Getting handles of swapchain images

#include "S13_Getting_handles_of_swapchain_images.h"

#include "Common.h"

namespace VKCookbook {

    bool GetHandlesOfSwapchainImages( VkDevice               logical_device,
                                      VkSwapchainKHR         swapchain,
                                      std::vector<VkImage> & swapchain_images ) {
        uint32_t images_count = 0;
        VkResult result = VK_SUCCESS;

        result = vkGetSwapchainImagesKHR( logical_device, swapchain, &images_count, nullptr );
        if( (VK_SUCCESS != result) ||
            (0 == images_count) ) {
            std::cout << "Could not get the number of swapchain images." << std::endl;
            return false;
        }

        swapchain_images.resize( images_count );
        result = vkGetSwapchainImagesKHR( logical_device, swapchain, &images_count, swapchain_images.data() );
        if( (VK_SUCCESS != result) ||
            (0 == images_count) ) {
            std::cout << "Could not enumerate swapchain images." << std::endl;
            return false;
        }

        return true;
    }

}
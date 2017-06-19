//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  07 Selecting a number of swapchain images

#include "S07_Selecting_a_number_of_swapchain_images.h"

namespace VKCookbook {

    bool SelectNumberOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                        uint32_t                       & number_of_images ) {
        number_of_images = surface_capabilities.minImageCount + 1;
        if( (surface_capabilities.maxImageCount > 0) &&
                ( number_of_images > surface_capabilities.maxImageCount ) ) {
            number_of_images = surface_capabilities.maxImageCount;
        }
        return true;
    }

}
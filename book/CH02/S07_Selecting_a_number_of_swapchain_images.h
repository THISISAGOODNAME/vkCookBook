//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  07 Selecting a number of swapchain images

#ifndef VKCOOKBOOK_S07_SELECTING_A_NUMBER_OF_SWAPCHAIN_IMAGES_H
#define VKCOOKBOOK_S07_SELECTING_A_NUMBER_OF_SWAPCHAIN_IMAGES_H

#include "Common.h"

namespace VKCookbook {

    bool SelectNumberOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                        uint32_t                       & number_of_images );

};


#endif //VKCOOKBOOK_S07_SELECTING_A_NUMBER_OF_SWAPCHAIN_IMAGES_H

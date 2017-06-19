//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  08 Choosing a size of swapchain images

#ifndef VKCOOKBOOK_S08_CHOOSING_A_SIZE_OF_SWAPCHAIN_IMAGES_H
#define VKCOOKBOOK_S08_CHOOSING_A_SIZE_OF_SWAPCHAIN_IMAGES_H

#include "Common.h"

namespace VKCookbook {

    bool ChooseSizeOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                      VkExtent2D                     & size_of_images );

};


#endif //VKCOOKBOOK_S08_CHOOSING_A_SIZE_OF_SWAPCHAIN_IMAGES_H

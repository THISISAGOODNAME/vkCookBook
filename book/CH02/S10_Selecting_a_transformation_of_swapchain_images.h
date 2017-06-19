//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  10 Selecting a transformation of swapchain images

#ifndef VKCOOKBOOK_S10_SELECTING_A_TRANSFORMATION_OF_SWAPCHAIN_IMAGES_H
#define VKCOOKBOOK_S10_SELECTING_A_TRANSFORMATION_OF_SWAPCHAIN_IMAGES_H

#include "Common.h"

namespace VKCookbook {

    bool SelectTransformationOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                                VkSurfaceTransformFlagBitsKHR    desired_transform,
                                                VkSurfaceTransformFlagBitsKHR  & surface_transform );

};


#endif //VKCOOKBOOK_S10_SELECTING_A_TRANSFORMATION_OF_SWAPCHAIN_IMAGES_H

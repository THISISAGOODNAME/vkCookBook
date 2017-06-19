//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  10 Selecting a transformation of swapchain images

#include "S10_Selecting_a_transformation_of_swapchain_images.h"

namespace VKCookbook {

    bool SelectTransformationOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                                VkSurfaceTransformFlagBitsKHR    desired_transform,
                                                VkSurfaceTransformFlagBitsKHR  & surface_transform ) {
        if( surface_capabilities.supportedTransforms & desired_transform ) {
            surface_transform = desired_transform;
        } else {
            surface_transform = surface_capabilities.currentTransform;
        }
        return true;
    }

}
//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  09 Selecting desired usage scenarios of swapchain images

#include "S09_Selecting_desired_usage_scenarios_of_swapchain_images.h"

namespace VKCookbook {

    bool SelectDesiredUsageScenariosOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                                       VkImageUsageFlags                desired_usages,
                                                       VkImageUsageFlags              & image_usage ) {
        image_usage = desired_usages & surface_capabilities.supportedUsageFlags;

        return desired_usages == image_usage;
    }

}
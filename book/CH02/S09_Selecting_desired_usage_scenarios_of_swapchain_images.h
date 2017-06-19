//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  09 Selecting desired usage scenarios of swapchain images

#ifndef VKCOOKBOOK_S09_SELECTING_DESIRED_USAGE_SCENARIOS_OF_SWAPCHAIN_IMAGES_H
#define VKCOOKBOOK_S09_SELECTING_DESIRED_USAGE_SCENARIOS_OF_SWAPCHAIN_IMAGES_H

#include "Common.h"

namespace VKCookbook {

    bool SelectDesiredUsageScenariosOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                                       VkImageUsageFlags                desired_usages,
                                                       VkImageUsageFlags              & image_usage );

};


#endif //VKCOOKBOOK_S09_SELECTING_DESIRED_USAGE_SCENARIOS_OF_SWAPCHAIN_IMAGES_H

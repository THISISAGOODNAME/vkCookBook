//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  05 Selecting a desired presentation mode

#ifndef VKCOOKBOOK_S05_SELECTING_A_DESIRED_PRESENTATION_MODE_H
#define VKCOOKBOOK_S05_SELECTING_A_DESIRED_PRESENTATION_MODE_H

#include "Common.h"

namespace VKCookbook {

    bool SelectDesiredPresentationMode( VkPhysicalDevice   physical_device,
                                        VkSurfaceKHR       presentation_surface,
                                        VkPresentModeKHR   desired_present_mode,
                                        VkPresentModeKHR & present_mode );

};


#endif //VKCOOKBOOK_S05_SELECTING_A_DESIRED_PRESENTATION_MODE_H

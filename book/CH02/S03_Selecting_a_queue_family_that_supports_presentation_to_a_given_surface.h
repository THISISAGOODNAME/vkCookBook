//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  03 Selecting a queue family that supports presentation to a given surface

#ifndef VKCOOKBOOK_S03_SELECTING_A_QUEUE_FAMILY_THAT_SUPPORTS_PRESENTATION_TO_A_GIVEN_SURFACE_H
#define VKCOOKBOOK_S03_SELECTING_A_QUEUE_FAMILY_THAT_SUPPORTS_PRESENTATION_TO_A_GIVEN_SURFACE_H


#include "Common.h"

namespace VKCookbook {

    bool SelectQueueFamilyThatSupportsPresentationToGivenSurface( VkPhysicalDevice   physical_device,
                                                                  VkSurfaceKHR       presentation_surface,
                                                                  uint32_t         & queue_family_index );

};


#endif //VKCOOKBOOK_S03_SELECTING_A_QUEUE_FAMILY_THAT_SUPPORTS_PRESENTATION_TO_A_GIVEN_SURFACE_H

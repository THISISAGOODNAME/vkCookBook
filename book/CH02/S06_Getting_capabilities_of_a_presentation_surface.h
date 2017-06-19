//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  06 Getting capabilities of a presentation surface

#ifndef VKCOOKBOOK_S06_GETTING_CAPABILITIES_OF_A_PRESENTATION_SURFACE_H
#define VKCOOKBOOK_S06_GETTING_CAPABILITIES_OF_A_PRESENTATION_SURFACE_H


#include "Common.h"

namespace VKCookbook {

    bool GetCapabilitiesOfPresentationSurface( VkPhysicalDevice           physical_device,
                                               VkSurfaceKHR               presentation_surface,
                                               VkSurfaceCapabilitiesKHR & surface_capabilities );

};


#endif //VKCOOKBOOK_S06_GETTING_CAPABILITIES_OF_A_PRESENTATION_SURFACE_H

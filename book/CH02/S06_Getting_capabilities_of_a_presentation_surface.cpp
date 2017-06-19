//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  06 Getting capabilities of a presentation surface

#include "S06_Getting_capabilities_of_a_presentation_surface.h"

namespace VKCookbook {

    bool GetCapabilitiesOfPresentationSurface( VkPhysicalDevice           physical_device,
                                               VkSurfaceKHR               presentation_surface,
                                               VkSurfaceCapabilitiesKHR & surface_capabilities ) {
        VkResult result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR( physical_device, presentation_surface, &surface_capabilities );

        if( VK_SUCCESS != result ) {
            std::cout << "Could not get the capabilities of a presentation surface." << std::endl;
            return false;
        }
        return true;
    }

}
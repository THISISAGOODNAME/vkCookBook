//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  03 Selecting a queue family that supports presentation to a given surface

#include "../CH01/S13_Checking_available_queue_families_and_their_properties.h"
#include "S03_Selecting_a_queue_family_that_supports_presentation_to_a_given_surface.h"

namespace VKCookbook {

    bool SelectQueueFamilyThatSupportsPresentationToGivenSurface( VkPhysicalDevice   physical_device,
                                                                  VkSurfaceKHR       presentation_surface,
                                                                  uint32_t         & queue_family_index ) {
        std::vector<VkQueueFamilyProperties> queue_families;
        if ( !CheckAvailableQueueFamiliesAndTheirProperties( physical_device, queue_families ) ) {
            return false;
        }

        for ( uint32_t index = 0; index < static_cast<uint32_t>(queue_families.size()); ++index) {
            VkBool32 presentation_supported = VK_FALSE;
            VkResult result = vkGetPhysicalDeviceSurfaceSupportKHR( physical_device, index, presentation_surface, &presentation_supported );
            if ( (VK_SUCCESS == result) && (VK_TRUE == presentation_supported) ) {
                queue_family_index = index;
                return true;
            }
        }

        return false;
    }

}
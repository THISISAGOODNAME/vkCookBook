//
// Created by aicdg on 2017/6/17.
//

#include "S13_Checking_available_queue_families_and_their_properties.h"
#include "S14_Selecting_index_of_a_queue_family_with_desired_capabilities.h"

namespace VKCookbook {

    bool SelectIndexOfQueueFamilyWithDesiredCapabilities( VkPhysicalDevice   physical_device,
                                                          VkQueueFlags       desired_capabilities,
                                                          uint32_t         & queue_family_index ) {
        std::vector<VkQueueFamilyProperties> queue_families;
        if( !CheckAvailableQueueFamiliesAndTheirProperties( physical_device, queue_families ) ) {
            return false;
        }

        for ( uint32_t index = 0; index < static_cast<uint32_t>(queue_families.size()); ++index) {
            if( (queue_families[index].queueCount > 0) &&
                (queue_families[index].queueFlags & desired_capabilities) ) {
                queue_family_index = index;
                return true;
            }
        }
        return false;
    }

}
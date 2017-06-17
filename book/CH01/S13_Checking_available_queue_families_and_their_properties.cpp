//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  13 Checking available queue families and their properties

#include "S13_Checking_available_queue_families_and_their_properties.h"

namespace VKCookbook {

    bool CheckAvailableQueueFamiliesAndTheirProperties( VkPhysicalDevice                       physical_device,
                                                        std::vector<VkQueueFamilyProperties> & queue_families ) {
        uint32_t queue_families_count = 0;

        vkGetPhysicalDeviceQueueFamilyProperties( physical_device, &queue_families_count, nullptr );
        if( queue_families_count == 0 ) {
            std::cout << "Could not get the number of queue families." << std::endl;
            return false;
        }

        queue_families.resize( queue_families_count );
        vkGetPhysicalDeviceQueueFamilyProperties( physical_device, &queue_families_count, queue_families.data() );
        if( queue_families_count == 0 ) {
            std::cout << "Could not acquire properties of queue families." << std::endl;
            return false;
        }

        return true;
    }

}

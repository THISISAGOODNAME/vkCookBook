//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  10 Enumerating available physical devices

#include "S10_Enumerating_available_physical_devices.h"

namespace VKCookbook {

    bool EnumerateAvailablePhysicalDevices( VkInstance                      instance,
                                            std::vector<VkPhysicalDevice> & available_devices ) {
        uint32_t devices_count = 0;
        VkResult result = VK_SUCCESS;

        result = vkEnumeratePhysicalDevices( instance, &devices_count, nullptr );
        if ( (result != VK_SUCCESS) || (devices_count == 0) ) {
            std::cout << "Could not get the number of available physical devices." << std::endl;
            return false;
        }

        available_devices.resize( devices_count );
        result = vkEnumeratePhysicalDevices( instance, &devices_count, available_devices.data() );
        if( (result != VK_SUCCESS) ||
            (devices_count == 0) ) {
            std::cout << "Could not enumerate physical devices." << std::endl;
            return false;
        }

        return true;
    }

}

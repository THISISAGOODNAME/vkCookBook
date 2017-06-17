//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  11 Checking available device extensions

#include "S11_Checking_available_device_extensions.h"

namespace VKCookbook {

    bool CheckAvailableDeviceExtensions( VkPhysicalDevice                     physical_device,
                                         std::vector<VkExtensionProperties> & available_extensions ) {
        uint32_t extensions_count = 0;
        VkResult result = VK_SUCCESS;

        result = vkEnumerateDeviceExtensionProperties( physical_device, nullptr, &extensions_count, nullptr );
        if( (result != VK_SUCCESS) ||
            (extensions_count == 0) ) {
            std::cout << "Could not get the number of device extensions." << std::endl;
            return false;
        }

        available_extensions.resize( extensions_count );
        result = vkEnumerateDeviceExtensionProperties( physical_device, nullptr, &extensions_count, available_extensions.data() );
        if( (result != VK_SUCCESS) ||
            (extensions_count == 0) ) {
            std::cout << "Could not enumerate device extensions." << std::endl;
            return false;
        }

        return true;
    }

}
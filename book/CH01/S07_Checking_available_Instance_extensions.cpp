//
// Created by aicdg on 2017/6/14.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  07 Checking available Instance extensions


#include "S07_Checking_available_Instance_extensions.h"

namespace VKCookbook {

    bool CheckAvailableInstanceExtensions( std::vector<VkExtensionProperties> & available_extensions ) {
        uint32_t extensions_count = 0;
        VkResult result = VK_SUCCESS;

        result = vkEnumerateInstanceExtensionProperties( nullptr, &extensions_count, nullptr );
        if( (result != VK_SUCCESS) ||
            (extensions_count == 0) ) {
            std::cout << "Could not get the number of instance extensions." << std::endl;
            return false;
        }

        available_extensions.resize( extensions_count );
        result = vkEnumerateInstanceExtensionProperties( nullptr, &extensions_count, available_extensions.data() );
        if( (result != VK_SUCCESS) ||
            (extensions_count == 0) ) {
            std::cout << "Could not enumerate instance extensions." << std::endl;
            return false;
        }

        return true;
    }

}
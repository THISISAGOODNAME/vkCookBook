//
// Created by yangyanjun on 2017/6/13.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  03 Connecting with a Vulkan Loader library

#include <iostream>
#include "S03_Connecting_with_a_Vulkan_Loader_library.h"

namespace VKCookbook {

    bool ConnectWithVulkanLoaderLibrary( LIBRARY_TYPE & vulkan_library ) {
#if defined _WIN32
        vulkan_library = LoadLibrary( "vulkan-1.dll" );
#elif defined __linux
        vulkan_library = dlopen( "libvulkan.so.1", RTLD_NOW );
#endif

        if (vulkan_library == nullptr) {
            std::cout << "Could not connect with a Vulkan Runtime library." << std::endl;
            return false;
        }

        return true;
    }

};
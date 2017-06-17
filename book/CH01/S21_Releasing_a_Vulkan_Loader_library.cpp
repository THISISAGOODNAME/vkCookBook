//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  21 Releasing a Vulkan Loader library

#include "S21_Releasing_a_Vulkan_Loader_library.h"

namespace VKCookbook {

    void ReleaseVulkanLoaderLibrary( LIBRARY_TYPE & vulkan_library ) {
        if ( nullptr != vulkan_library ) {
#if defined _WIN32
            FreeLibrary( vulkan_library );

#elif defined __linux
            dlclose( vulkan_library );
#endif
            vulkan_library = nullptr;
        }
    }

}
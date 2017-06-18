//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  01 Creating a Vulkan Instance with WSI extensions enabled

#include "../CH01/S08_Creating_a_Vulkan_Instance.h"
#include "S01_Creating_a_Vulkan_Instance_with_WSI_extensions_enabled.h"

namespace VKCookbook {

    bool CreateVulkanInstanceWithWsiExtensionsEnabled( std::vector<char const *> & desired_extensions,
                                                       char const * const          application_name,
                                                       VkInstance                & instance ) {
        desired_extensions.emplace_back( VK_KHR_SURFACE_EXTENSION_NAME );
        desired_extensions.emplace_back(
#ifdef VK_USE_PLATFORM_WIN32_KHR
                VK_KHR_WIN32_SURFACE_EXTENSION_NAME

#elif defined VK_USE_PLATFORM_XCB_KHR
                VK_KHR_XCB_SURFACE_EXTENSION_NAME

#elif defined VK_USE_PLATFORM_XLIB_KHR
                VK_KHR_XLIB_SURFACE_EXTENSION_NAME
#endif
        );

        return CreateVulkanInstance( desired_extensions, application_name, instance );
    }

}
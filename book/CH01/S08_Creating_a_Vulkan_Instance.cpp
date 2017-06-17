//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  08 Creating a Vulkan Instance

#include "S07_Checking_available_Instance_extensions.h"
#include "S08_Creating_a_Vulkan_Instance.h"

namespace VKCookbook {
    bool CreateVulkanInstance( std::vector<char const *> const & desired_extensions,
                               char const * const                application_name,
                               VkInstance                        & instance ) {
        std::vector<VkExtensionProperties> available_extensions;
        if ( !CheckAvailableInstanceExtensions( available_extensions ) ) {
            return false;
        }

        for ( auto & extension : desired_extensions ) {
            if ( !IsExtensionSupported( available_extensions, extension ) ) {
                std::cout << "Extension named '" << extension << "' is not supported by an Instance object." << std::endl;
                return false;
            }
        }

        VkApplicationInfo application_info = {
                VK_STRUCTURE_TYPE_APPLICATION_INFO,                 // VkStructureType           sType
                nullptr,                                           // const void              * pNext
                application_name,                                   // const char              * pApplicationName
                VK_MAKE_VERSION( 1, 0, 0 ),                         // uint32_t                  applicationVersion
                "Vulkan Cookbook",                                  // const char              * pEngineName
                VK_MAKE_VERSION( 1, 0, 0 ),                         // uint32_t                  engineVersion
                VK_MAKE_VERSION( 1, 0, 0 )                          // uint32_t                  apiVersion
        };

        VkInstanceCreateInfo instance_create_info = {
                VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,                // VkStructureType           sType
                nullptr,                                             // const void              * pNext
                0,                                                    // VkInstanceCreateFlags     flags
                &application_info,                                    // const VkApplicationInfo * pApplicationInfo
                0,                                                    // uint32_t                  enabledLayerCount
                nullptr,                                             // const char * const      * ppEnabledLayerNames
                static_cast<uint32_t>(desired_extensions.size()),   // uint32_t                  enabledExtensionCount
                desired_extensions.data()                            // const char * const      * ppEnabledExtensionNames
        };

        VkResult result = vkCreateInstance ( &instance_create_info, nullptr, &instance );
        if ( (result != VK_SUCCESS) || (instance == VK_NULL_HANDLE) ) {
            std::cout << "Could not create Vulkan instance." << std::endl;
            return false;
        }

        return true;
    }
}
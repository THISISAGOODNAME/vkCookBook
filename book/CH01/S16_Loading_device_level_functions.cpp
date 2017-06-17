//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  16 Loading device-level functions

#include "S16_Loading_device_level_functions.h"

namespace VKCookbook {

    bool LoadDeviceLevelFunctions( VkDevice                          logical_device,
                                   std::vector<char const *> const & enabled_extensions ) {
        // Load core Vulkan API device-level functions
#define DEVICE_LEVEL_VULKAN_FUNCTION( name )                                    \
    name = (PFN_##name)vkGetDeviceProcAddr( logical_device, #name );            \
    if( name == nullptr ) {                                                     \
      std::cout << "Could not load device-level Vulkan function named: "        \
        #name << std::endl;                                                     \
      return false;                                                             \
    }

        // Load device-level functions from enabled extensions
#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension )          \
    for( auto & enabled_extension : enabled_extensions ) {                      \
      if( std::string( enabled_extension ) == std::string( extension ) ) {      \
        name = (PFN_##name)vkGetDeviceProcAddr( logical_device, #name );        \
        if( name == nullptr ) {                                                 \
          std::cout << "Could not load device-level Vulkan function named: "    \
            #name << std::endl;                                                 \
          return false;                                                         \
        }                                                                       \
      }                                                                         \
    }

#include "ListOfVulkanFunctions.inl"

        return true;
    }

}
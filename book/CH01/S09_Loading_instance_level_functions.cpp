//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  09 Loading instance-level functions

#include "S09_Loading_instance_level_functions.h"

namespace VKCookbook {
    bool LoadInstanceLevelFunctions( VkInstance                        instance,
                                     std::vector<char const *> const & enabled_extensions ) {
        // Load core Vulkan API instance-level functions
#define INSTANCE_LEVEL_VULKAN_FUNCTION( name )                                  \
    name = (PFN_##name)vkGetInstanceProcAddr( instance, #name );                \
    if( name == nullptr ) {                                                     \
      std::cout << "Could not load instance-level Vulkan function named: "      \
        #name << std::endl;                                                     \
      return false;                                                             \
    }

        // Load instance-level functions from enabled extensions
#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension )        \
    for( auto & enabled_extension : enabled_extensions ) {                      \
      if( std::string( enabled_extension ) == std::string( extension ) ) {      \
        name = (PFN_##name)vkGetInstanceProcAddr( instance, #name );            \
        if( name == nullptr ) {                                                 \
          std::cout << "Could not load instance-level Vulkan function named: "  \
            #name << std::endl;                                                 \
          return false;                                                         \
        }                                                                       \
      }                                                                         \
    }

#include "ListOfVulkanFunctions.inl"

        return true;
    }
}

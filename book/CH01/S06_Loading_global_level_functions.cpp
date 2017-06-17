//
// Created by aicdg on 2017/6/14.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  06 Loading global-level functions

#include "S06_Loading_global_level_functions.h"

namespace VKCookbook {

    bool LoadGlobalLevelFunctions() {
#define GLOBAL_LEVEL_VULKAN_FUNCTION( name )                              \
    name = (PFN_##name)vkGetInstanceProcAddr( nullptr, #name );           \
    if( name == nullptr ) {                                               \
      std::cout << "Could not load global level Vulkan function named: "  \
        #name << std::endl;                                               \
      return false;                                                       \
    }

#include "ListOfVulkanFunctions.inl"

        return true;
    }

}
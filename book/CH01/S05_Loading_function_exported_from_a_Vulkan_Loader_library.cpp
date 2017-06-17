//
// Created by aicdg on 2017/6/13.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  05 Loading function exported from a Vulkan Loader library

#include "S05_Loading_function_exported_from_a_Vulkan_Loader_library.h"

namespace VKCookbook {

    bool LoadFunctionExportedFromVulkanLoaderLibrary( LIBRARY_TYPE const & vulkan_library ) {
#if defined _WIN32
#define LoadFunction GetProcAddress
#elif defined __linux
#define LoadFunction dlsym
#endif

#define EXPORTED_VULKAN_FUNCTION( name )                              \
    name = (PFN_##name)LoadFunction( vulkan_library, #name );         \
    if( name == nullptr ) {                                           \
      std::cout << "Could not load exported Vulkan function named: "  \
        #name << std::endl;                                           \
      return false;                                                   \
    }

#include "ListOfVulkanFunctions.inl"

        return true;
    }

} // namespace VulkanCookbook
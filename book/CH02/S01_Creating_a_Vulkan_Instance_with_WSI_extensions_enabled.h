//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  01 Creating a Vulkan Instance with WSI extensions enabled

#ifndef VKCOOKBOOK_S01_CREATING_A_VULKAN_INSTANCE_WITH_WSI_EXTENSIONS_ENABLED_H
#define VKCOOKBOOK_S01_CREATING_A_VULKAN_INSTANCE_WITH_WSI_EXTENSIONS_ENABLED_H

#include "Common.h"

namespace VKCookbook {

    bool CreateVulkanInstanceWithWsiExtensionsEnabled( std::vector<char const *> & desired_extensions,
                                                       char const * const          application_name,
                                                       VkInstance                & instance );

};


#endif //VKCOOKBOOK_S01_CREATING_A_VULKAN_INSTANCE_WITH_WSI_EXTENSIONS_ENABLED_H

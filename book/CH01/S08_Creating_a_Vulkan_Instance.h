//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  08 Creating a Vulkan Instance

#ifndef VKCOOKBOOK_S08_CREATING_A_VULKAN_INSTANCE_H
#define VKCOOKBOOK_S08_CREATING_A_VULKAN_INSTANCE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateVulkanInstance( std::vector<char const *> const & desired_extensions,
                               char const * const                application_name,
                               VkInstance                        & instance );

};


#endif //VKCOOKBOOK_S08_CREATING_A_VULKAN_INSTANCE_H

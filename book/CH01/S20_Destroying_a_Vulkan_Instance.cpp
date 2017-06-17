//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  20 Destroying a Vulkan Instance

#include "S20_Destroying_a_Vulkan_Instance.h"

namespace VKCookbook {

    void DestroyVulkanInstance( VkInstance & instance ) {
        if ( instance ) {
            vkDestroyInstance( instance, nullptr );
            instance = VK_NULL_HANDLE;
        }
    }

}
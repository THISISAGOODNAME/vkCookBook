//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  19 Destroying a logical device

#include "S19_Destroying_a_logical_device.h"

namespace VKCookbook {

    void DestroyLogicalDevice( VkDevice & logical_device ) {
        if ( logical_device ) {
            vkDestroyDevice( logical_device, nullptr );
            logical_device = VK_NULL_HANDLE;
        }
    }

}
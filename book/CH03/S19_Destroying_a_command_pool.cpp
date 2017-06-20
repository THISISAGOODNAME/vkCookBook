//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  19 Destroying a command pool

#include "S19_Destroying_a_command_pool.h"

namespace VKCookbook {

    void DestroyCommandPool( VkDevice        logical_device,
                             VkCommandPool & command_pool ) {
        if( VK_NULL_HANDLE != command_pool ) {
            vkDestroyCommandPool( logical_device, command_pool, nullptr );
            command_pool = VK_NULL_HANDLE;
        }
    }

}
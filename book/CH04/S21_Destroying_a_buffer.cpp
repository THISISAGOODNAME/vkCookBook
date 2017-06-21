//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  21 Destroying a buffer

#include "S21_Destroying_a_buffer.h"

namespace VKCookbook {

    void DestroyBuffer( VkDevice   logical_device,
                        VkBuffer & buffer ) {
        if( VK_NULL_HANDLE != buffer ) {
            vkDestroyBuffer( logical_device, buffer, nullptr );
            buffer = VK_NULL_HANDLE;
        }
    }

}
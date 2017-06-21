//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  19 Destroying a buffer view

#include "S19_Destroying_a_buffer_view.h"

namespace VKCookbook {

    void DestroyBufferView( VkDevice       logical_device,
                            VkBufferView & buffer_view ) {
        if( VK_NULL_HANDLE != buffer_view ) {
            vkDestroyBufferView( logical_device, buffer_view, nullptr );
            buffer_view = VK_NULL_HANDLE;
        }
    }

}
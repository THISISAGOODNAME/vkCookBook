//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  16 Destroying a fence

#include "S16_Destroying_a_fence.h"

namespace VKCookbook {

    void DestroyFence( VkDevice   logical_device,
                       VkFence  & fence ) {
        if ( VK_NULL_HANDLE != fence ) {
            vkDestroyFence( logical_device, fence, nullptr );
            fence = VK_NULL_HANDLE;
        }
    }

}

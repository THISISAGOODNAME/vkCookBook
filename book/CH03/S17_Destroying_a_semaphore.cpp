//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  17 Destroying a semaphore

#include "S17_Destroying_a_semaphore.h"

namespace VKCookbook {

    void DestroySemaphore( VkDevice      logical_device,
                           VkSemaphore & semaphore ) {
        if( VK_NULL_HANDLE != semaphore ) {
            vkDestroySemaphore( logical_device, semaphore, nullptr );
            semaphore = VK_NULL_HANDLE;
        }
    }

}

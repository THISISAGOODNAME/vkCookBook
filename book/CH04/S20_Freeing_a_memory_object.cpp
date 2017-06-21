//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  20 Freeing a memory object

#include "S20_Freeing_a_memory_object.h"

namespace VKCookbook {

    void FreeMemoryObject( VkDevice         logical_device,
                           VkDeviceMemory & memory_object ){
        if( VK_NULL_HANDLE != memory_object ) {
            vkFreeMemory( logical_device, memory_object, nullptr );
            memory_object = VK_NULL_HANDLE;
        }
    }

}
//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  02 Allocating and binding memory object to a buffer

#ifndef VKCOOKBOOK_S02_ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_A_BUFFER_H
#define VKCOOKBOOK_S02_ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_A_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool AllocateAndBindMemoryObjectToBuffer( VkPhysicalDevice           physical_device,
                                              VkDevice                   logical_device,
                                              VkBuffer                   buffer,
                                              VkMemoryPropertyFlagBits   memory_properties,
                                              VkDeviceMemory           & memory_object );

};


#endif //VKCOOKBOOK_S02_ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_A_BUFFER_H

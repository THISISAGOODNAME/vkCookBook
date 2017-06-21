//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  08 Creating a storage buffer

#ifndef VKCOOKBOOK_S08_CREATING_A_STORAGE_BUFFER_H
#define VKCOOKBOOK_S08_CREATING_A_STORAGE_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool CreateStorageBuffer( VkPhysicalDevice     physical_device,
                              VkDevice             logical_device,
                              VkDeviceSize         size,
                              VkBufferUsageFlags   usage,
                              VkBuffer           & storage_buffer,
                              VkDeviceMemory     & memory_object );

};


#endif //VKCOOKBOOK_S08_CREATING_A_STORAGE_BUFFER_H

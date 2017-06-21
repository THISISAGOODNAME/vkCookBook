//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  06 Creating a storage texel buffer

#ifndef VKCOOKBOOK_S06_CREATING_A_STORAGE_TEXEL_BUFFER_H
#define VKCOOKBOOK_S06_CREATING_A_STORAGE_TEXEL_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool CreateStorageTexelBuffer( VkPhysicalDevice     physical_device,
                                   VkDevice             logical_device,
                                   VkFormat             format,
                                   VkDeviceSize         size,
                                   VkBufferUsageFlags   usage,
                                   bool                 atomic_operations,
                                   VkBuffer           & storage_texel_buffer,
                                   VkDeviceMemory     & memory_object,
                                   VkBufferView       & storage_texel_buffer_view );

};


#endif //VKCOOKBOOK_S06_CREATING_A_STORAGE_TEXEL_BUFFER_H

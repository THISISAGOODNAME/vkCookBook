//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  07 Creating a uniform buffer

#ifndef VKCOOKBOOK_S07_CREATING_A_UNIFORM_BUFFER_H
#define VKCOOKBOOK_S07_CREATING_A_UNIFORM_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool CreateUniformBuffer( VkPhysicalDevice     physical_device,
                              VkDevice             logical_device,
                              VkDeviceSize         size,
                              VkBufferUsageFlags   usage,
                              VkBuffer           & uniform_buffer,
                              VkDeviceMemory     & memory_object );

};


#endif //VKCOOKBOOK_S07_CREATING_A_UNIFORM_BUFFER_H

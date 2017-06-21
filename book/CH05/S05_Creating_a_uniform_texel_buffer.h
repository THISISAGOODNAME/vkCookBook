//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  05 Creating a uniform texel buffer

#ifndef VKCOOKBOOK_S05_CREATING_A_UNIFORM_TEXEL_BUFFER_H
#define VKCOOKBOOK_S05_CREATING_A_UNIFORM_TEXEL_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool CreateUniformTexelBuffer( VkPhysicalDevice     physical_device,
                                   VkDevice             logical_device,
                                   VkFormat             format,
                                   VkDeviceSize         size,
                                   VkImageUsageFlags    usage,
                                   VkBuffer           & uniform_texel_buffer,
                                   VkDeviceMemory     & memory_object,
                                   VkBufferView       & uniform_texel_buffer_view );

};


#endif //VKCOOKBOOK_S05_CREATING_A_UNIFORM_TEXEL_BUFFER_H

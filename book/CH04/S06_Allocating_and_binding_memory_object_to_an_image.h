//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  06 Allocating and binding memory object to an image

#ifndef VKCOOKBOOK_S06_ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_AN_IMAGE_H
#define VKCOOKBOOK_S06_ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_AN_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    bool AllocateAndBindMemoryObjectToImage( VkPhysicalDevice           physical_device,
                                             VkDevice                   logical_device,
                                             VkImage                    image,
                                             VkMemoryPropertyFlagBits   memory_properties,
                                             VkDeviceMemory           & memory_object );

};


#endif //VKCOOKBOOK_S06_ALLOCATING_AND_BINDING_MEMORY_OBJECT_TO_AN_IMAGE_H

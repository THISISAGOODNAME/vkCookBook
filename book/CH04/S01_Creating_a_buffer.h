//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  01 Creating a buffer

#ifndef VKCOOKBOOK_S01_CREATING_A_BUFFER_H
#define VKCOOKBOOK_S01_CREATING_A_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool CreateBuffer( VkDevice             logical_device,
                       VkDeviceSize         size,
                       VkBufferUsageFlags   usage,
                       VkBuffer           & buffer );

};


#endif //VKCOOKBOOK_S01_CREATING_A_BUFFER_H

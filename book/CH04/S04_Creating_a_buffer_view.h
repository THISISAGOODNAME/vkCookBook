//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  04 Creating a buffer view

#ifndef VKCOOKBOOK_S04_CREATING_A_BUFFER_VIEW_H
#define VKCOOKBOOK_S04_CREATING_A_BUFFER_VIEW_H

#include "Common.h"

namespace VKCookbook {

    bool CreateBufferView( VkDevice       logical_device,
                           VkBuffer       buffer,
                           VkFormat       format,
                           VkDeviceSize   memory_offset,
                           VkDeviceSize   memory_range,
                           VkBufferView & buffer_view );

};


#endif //VKCOOKBOOK_S04_CREATING_A_BUFFER_VIEW_H

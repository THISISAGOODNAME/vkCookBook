//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  20 Freeing a memory object

#ifndef VKCOOKBOOK_S20_FREEING_A_MEMORY_OBJECT_H
#define VKCOOKBOOK_S20_FREEING_A_MEMORY_OBJECT_H

#include "Common.h"

namespace VKCookbook {

    void FreeMemoryObject( VkDevice         logical_device,
                           VkDeviceMemory & memory_object );

};


#endif //VKCOOKBOOK_S20_FREEING_A_MEMORY_OBJECT_H

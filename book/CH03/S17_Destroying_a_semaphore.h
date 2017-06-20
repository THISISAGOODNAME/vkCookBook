//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  17 Destroying a semaphore

#ifndef VKCOOKBOOK_S17_DESTROYING_A_SEMAPHORE_H
#define VKCOOKBOOK_S17_DESTROYING_A_SEMAPHORE_H

#include "Common.h"

namespace VKCookbook {

    void DestroySemaphore( VkDevice      logical_device,
                           VkSemaphore & semaphore );

};


#endif //VKCOOKBOOK_S17_DESTROYING_A_SEMAPHORE_H

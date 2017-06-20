//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  07 Creating a semaphore

#ifndef VKCOOKBOOK_S07_CREATING_A_SEMAPHORE_H
#define VKCOOKBOOK_S07_CREATING_A_SEMAPHORE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateSemaphore( VkDevice      logical_device,
                          VkSemaphore & semaphore );

};


#endif //VKCOOKBOOK_S07_CREATING_A_SEMAPHORE_H

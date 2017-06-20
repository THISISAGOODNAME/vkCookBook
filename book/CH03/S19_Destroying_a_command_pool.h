//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  19 Destroying a command pool

#ifndef VKCOOKBOOK_S19_DESTROYING_A_COMMAND_POOL_H
#define VKCOOKBOOK_S19_DESTROYING_A_COMMAND_POOL_H

#include "Common.h"

namespace VKCookbook {

    void DestroyCommandPool( VkDevice        logical_device,
                             VkCommandPool & command_pool );

};


#endif //VKCOOKBOOK_S19_DESTROYING_A_COMMAND_POOL_H

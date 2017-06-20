//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  01 Creating a command pool

#ifndef VKCOOKBOOK_S01_CREATING_A_COMMAND_POOL_H
#define VKCOOKBOOK_S01_CREATING_A_COMMAND_POOL_H

#include "Common.h"

namespace VKCookbook {

    bool CreateCommandPool( VkDevice                   logical_device,
                            VkCommandPoolCreateFlags   command_pool_flags,
                            uint32_t                   queue_family,
                            VkCommandPool            & command_pool );

};


#endif //VKCOOKBOOK_S01_CREATING_A_COMMAND_POOL_H

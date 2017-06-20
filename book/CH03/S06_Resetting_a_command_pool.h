//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  06 Resetting a command pool

#ifndef VKCOOKBOOK_S06_RESETTING_A_COMMAND_POOL_H
#define VKCOOKBOOK_S06_RESETTING_A_COMMAND_POOL_H

#include "Common.h"

namespace VKCookbook {

    bool ResetCommandPool( VkDevice      logical_device,
                           VkCommandPool command_pool,
                           bool          release_resources );

};


#endif //VKCOOKBOOK_S06_RESETTING_A_COMMAND_POOL_H

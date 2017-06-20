//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  02 Allocating command buffers

#ifndef VKCOOKBOOK_S02_ALLOCATING_COMMAND_BUFFERS_H
#define VKCOOKBOOK_S02_ALLOCATING_COMMAND_BUFFERS_H

#include "Common.h"

namespace VKCookbook {

    bool AllocateCommandBuffers( VkDevice                       logical_device,
                                 VkCommandPool                  command_pool,
                                 VkCommandBufferLevel           level,
                                 uint32_t                       count,
                                 std::vector<VkCommandBuffer> & command_buffers );

};


#endif //VKCOOKBOOK_S02_ALLOCATING_COMMAND_BUFFERS_H

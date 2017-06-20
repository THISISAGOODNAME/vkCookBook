//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  18 Freeing command buffers

#ifndef VKCOOKBOOK_S18_FREEING_COMMAND_BUFFERS_H
#define VKCOOKBOOK_S18_FREEING_COMMAND_BUFFERS_H

#include "Common.h"

namespace VKCookbook {

    void FreeCommandBuffers( VkDevice                       logical_device,
                             VkCommandPool                  command_pool,
                             std::vector<VkCommandBuffer> & command_buffers );

};


#endif //VKCOOKBOOK_S18_FREEING_COMMAND_BUFFERS_H

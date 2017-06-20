//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  18 Freeing command buffers

#include "S18_Freeing_command_buffers.h"

namespace VKCookbook {

    void FreeCommandBuffers( VkDevice                       logical_device,
                             VkCommandPool                  command_pool,
                             std::vector<VkCommandBuffer> & command_buffers ) {
        if( command_buffers.size() > 0 ) {
            vkFreeCommandBuffers( logical_device, command_pool, static_cast<uint32_t>(command_buffers.size()), command_buffers.data() );
            command_buffers.clear();
        }
    }

}
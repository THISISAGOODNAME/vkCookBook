//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  05 Binding an index buffer

#include "S05_Binding_an_index_buffer.h"

namespace VKCookbook {

    void BindIndexBuffer( VkCommandBuffer   command_buffer,
                          VkBuffer          buffer,
                          VkDeviceSize      memory_offset,
                          VkIndexType       index_type ){
        vkCmdBindIndexBuffer( command_buffer, buffer, memory_offset, index_type );
    }

}
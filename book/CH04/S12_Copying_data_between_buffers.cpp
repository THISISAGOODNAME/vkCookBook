//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  12 Copying data between buffers

#include "S12_Copying_data_between_buffers.h"

namespace VKCookbook {

    void CopyDataBetweenBuffers( VkCommandBuffer           command_buffer,
                                 VkBuffer                  source_buffer,
                                 VkBuffer                  destination_buffer,
                                 std::vector<VkBufferCopy> regions ) {
        if( regions.size() > 0 ) {
            vkCmdCopyBuffer( command_buffer, source_buffer, destination_buffer, static_cast<uint32_t>(regions.size()), regions.data() );
        }
    }

}
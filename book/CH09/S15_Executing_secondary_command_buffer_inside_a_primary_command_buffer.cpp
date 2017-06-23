//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  15 Executing secondary command buffer inside a primary command buffer

#include "S15_Executing_secondary_command_buffer_inside_a_primary_command_buffer.h"

namespace VKCookbook {

    void ExecuteSecondaryCommandBufferInsidePrimaryCommandBuffer( VkCommandBuffer                      primary_command_buffer,
                                                                  std::vector<VkCommandBuffer> const & secondary_command_buffers ){
        if( secondary_command_buffers.size() > 0 ) {
            vkCmdExecuteCommands( primary_command_buffer, static_cast<uint32_t >(secondary_command_buffers.size()), secondary_command_buffers.data() );
        }
    }

}
//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  15 Executing secondary command buffer inside a primary command buffer

#ifndef VKCOOKBOOK_S15_EXECUTING_SECONDARY_COMMAND_BUFFER_INSIDE_A_PRIMARY_COMMAND_BUFFER_H
#define VKCOOKBOOK_S15_EXECUTING_SECONDARY_COMMAND_BUFFER_INSIDE_A_PRIMARY_COMMAND_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    void ExecuteSecondaryCommandBufferInsidePrimaryCommandBuffer( VkCommandBuffer                      primary_command_buffer,
                                                                  std::vector<VkCommandBuffer> const & secondary_command_buffers );

};


#endif //VKCOOKBOOK_S15_EXECUTING_SECONDARY_COMMAND_BUFFER_INSIDE_A_PRIMARY_COMMAND_BUFFER_H

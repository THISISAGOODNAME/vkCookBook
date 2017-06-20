//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  03 Beginning a command buffer recording operation

#ifndef VKCOOKBOOK_S03_BEGINNING_A_COMMAND_BUFFER_RECORDING_OPERATION_H
#define VKCOOKBOOK_S03_BEGINNING_A_COMMAND_BUFFER_RECORDING_OPERATION_H

#include "Common.h"

namespace VKCookbook {

    bool BeginCommandBufferRecordingOperation( VkCommandBuffer                  command_buffer,
                                               VkCommandBufferUsageFlags        usage,
                                               VkCommandBufferInheritanceInfo * secondary_command_buffer_info );

};


#endif //VKCOOKBOOK_S03_BEGINNING_A_COMMAND_BUFFER_RECORDING_OPERATION_H

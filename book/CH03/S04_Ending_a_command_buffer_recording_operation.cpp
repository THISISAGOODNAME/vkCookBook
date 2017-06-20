//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  04 Ending a command buffer recording operation

#include "S04_Ending_a_command_buffer_recording_operation.h"

namespace VKCookbook {

    bool EndCommandBufferRecordingOperation( VkCommandBuffer command_buffer ) {
        VkResult result = vkEndCommandBuffer( command_buffer );
        if( VK_SUCCESS != result ) {
            std::cout << "Error occurred during command buffer recording." << std::endl;
            return false;
        }
        return true;
    }

}
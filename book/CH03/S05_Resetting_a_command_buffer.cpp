//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  05 Resetting a command buffer

#include "S05_Resetting_a_command_buffer.h"

namespace VKCookbook {

    bool ResetCommandBuffer( VkCommandBuffer command_buffer,
                             bool            release_resources ) {
        VkResult result = vkResetCommandBuffer( command_buffer, release_resources ? VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT : 0 );
        if( VK_SUCCESS != result ) {
            std::cout << "Error occurred during command buffer reset." << std::endl;
            return false;
        }
        return true;
    }

}

//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  06 Resetting a command pool

#include "S06_Resetting_a_command_pool.h"

namespace VKCookbook {

    bool ResetCommandPool( VkDevice      logical_device,
                           VkCommandPool command_pool,
                           bool          release_resources ) {
        VkResult result = vkResetCommandPool( logical_device, command_pool, release_resources ? VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT : 0 );
        if( VK_SUCCESS != result ) {
            std::cout << "Error occurred during command pool reset." << std::endl;
            return false;
        }
        return true;
    }

}
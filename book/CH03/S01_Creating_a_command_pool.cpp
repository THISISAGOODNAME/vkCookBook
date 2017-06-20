//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  01 Creating a command pool

#include "S01_Creating_a_command_pool.h"

namespace VKCookbook {

    bool CreateCommandPool( VkDevice                   logical_device,
                            VkCommandPoolCreateFlags   command_pool_flags,
                            uint32_t                   queue_family,
                            VkCommandPool            & command_pool ) {
        VkCommandPoolCreateInfo command_pool_create_info = {
                VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,    // VkStructureType              sType
                nullptr,                                      // const void                 * pNext
                command_pool_flags,                            // VkCommandPoolCreateFlags     flags
                queue_family                                   // uint32_t                     queueFamilyIndex
        };

        VkResult result = vkCreateCommandPool( logical_device, &command_pool_create_info, nullptr, &command_pool );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create command pool." << std::endl;
            return false;
        }
        return true;
    }

}
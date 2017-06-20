//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  08 Creating a fence

#include "S08_Creating_a_fence.h"

namespace VKCookbook {

    bool CreateFence( VkDevice   logical_device,
                      bool       signaled,
                      VkFence  & fence ) {
        VkFenceCreateInfo fence_create_info = {
                VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,          // VkStructureType        sType
                nullptr,                                      // const void           * pNext
                signaled ? VK_FENCE_CREATE_SIGNALED_BIT : 0u, // VkFenceCreateFlags     flags
        };

        VkResult result = vkCreateFence( logical_device, &fence_create_info, nullptr, &fence );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create a fence." << std::endl;
            return false;
        }
        return true;
    }

}
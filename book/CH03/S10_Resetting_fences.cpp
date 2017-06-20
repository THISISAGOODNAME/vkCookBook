//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  10 Resetting fences

#include "S10_Resetting_fences.h"

namespace VKCookbook {

    bool ResetFences( VkDevice                     logical_device,
                      std::vector<VkFence> const & fences ) {
        if( fences.size() > 0 ) {
            VkResult result = vkResetFences( logical_device, static_cast<uint32_t>(fences.size()), fences.data() );
            if( VK_SUCCESS != result ) {
                std::cout << "Error occurred when tried to reset fences." << std::endl;
                return false;
            }
            return VK_SUCCESS == result;
        }
        return false;
    }

}
//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  09 Waiting for fences

#include "S09_Waiting_for_fences.h"

namespace VKCookbook {

    bool WaitForFences( VkDevice                     logical_device,
                        std::vector<VkFence> const & fences,
                        VkBool32                     wait_for_all,
                        uint64_t                     timeout ) {
        if( fences.size() > 0 ) {
            VkResult result = vkWaitForFences( logical_device, static_cast<uint32_t>(fences.size()), fences.data(), wait_for_all, timeout );
            if( VK_SUCCESS != result ) {
                std::cout << "Waiting on fence failed." << std::endl;
                return false;
            }
            return true;
        }
        return false;
    }

}
//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  17 Resetting a descriptor pool

#include "S17_Resetting_a_descriptor_pool.h"

namespace VKCookbook {

    bool ResetDescriptorPool( VkDevice          logical_device,
                              VkDescriptorPool  descriptor_pool ) {
        VkResult result = vkResetDescriptorPool( logical_device, descriptor_pool, 0 );
        if( VK_SUCCESS != result ) {
            std::cout << "Error occurred during descriptor pool reset." << std::endl;
            return false;
        }
        return true;
    }

}
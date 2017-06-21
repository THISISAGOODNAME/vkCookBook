//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  18 Destroying a descriptor pool

#include "S18_Destroying_a_descriptor_pool.h"

namespace VKCookbook {

    void DestroyDescriptorPool( VkDevice           logical_device,
                                VkDescriptorPool & descriptor_pool ) {
        if( VK_NULL_HANDLE != descriptor_pool ) {
            vkDestroyDescriptorPool( logical_device, descriptor_pool, nullptr );
            descriptor_pool = VK_NULL_HANDLE;
        }
    }

}
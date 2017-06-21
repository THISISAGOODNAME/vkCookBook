//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  20 Destroying a sampler

#include "S20_Destroying_a_sampler.h"

namespace VKCookbook {

    void DestroySampler( VkDevice    logical_device,
                         VkSampler & sampler ) {
        if( VK_NULL_HANDLE != sampler ) {
            vkDestroySampler( logical_device, sampler, nullptr );
            sampler = VK_NULL_HANDLE;
        }
    }

}
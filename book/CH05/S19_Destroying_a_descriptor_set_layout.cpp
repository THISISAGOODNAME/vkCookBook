//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  19 Destroying a descriptor set layout

#include "S19_Destroying_a_descriptor_set_layout.h"

namespace VKCookbook {

    void DestroyDescriptorSetLayout( VkDevice                logical_device,
                                     VkDescriptorSetLayout & descriptor_set_layout ) {
        if( VK_NULL_HANDLE != descriptor_set_layout ) {
            vkDestroyDescriptorSetLayout( logical_device, descriptor_set_layout, nullptr );
            descriptor_set_layout = VK_NULL_HANDLE;
        }
    }

}
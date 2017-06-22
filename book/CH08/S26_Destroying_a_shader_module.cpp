//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  26 Destroying a shader module

#include "S26_Destroying_a_shader_module.h"

namespace VKCookbook {

    void DestroyShaderModule( VkDevice         logical_device,
                              VkShaderModule & shader_module ){
        if( VK_NULL_HANDLE != shader_module ) {
            vkDestroyShaderModule( logical_device, shader_module, nullptr );
            shader_module = VK_NULL_HANDLE;
        }
    }

}
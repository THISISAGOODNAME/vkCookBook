//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  12 Destroying a render pass

#include "S12_Destroying_a_render_pass.h"

namespace VKCookbook {

    void DestroyRenderPass( VkDevice       logical_device,
                            VkRenderPass & render_pass ) {
        if( VK_NULL_HANDLE != render_pass ) {
            vkDestroyRenderPass( logical_device, render_pass, nullptr );
            render_pass = VK_NULL_HANDLE;
        }
    }

}
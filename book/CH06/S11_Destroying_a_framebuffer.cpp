//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  11 Destroying a framebuffer

#include "S11_Destroying_a_framebuffer.h"

namespace VKCookbook {

    void DestroyFramebuffer( VkDevice        logical_device,
                             VkFramebuffer & framebuffer ) {
        if( VK_NULL_HANDLE != framebuffer ) {
            vkDestroyFramebuffer( logical_device, framebuffer, nullptr );
            framebuffer = VK_NULL_HANDLE;
        }
    }

}
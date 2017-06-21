//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  08 Beginning a render pass

#ifndef VKCOOKBOOK_S08_BEGINNING_A_RENDER_PASS_H
#define VKCOOKBOOK_S08_BEGINNING_A_RENDER_PASS_H

#include "Common.h"

namespace VKCookbook {

    void BeginRenderPass( VkCommandBuffer                   command_buffer,
                          VkRenderPass                      render_pass,
                          VkFramebuffer                     framebuffer,
                          VkRect2D                          render_area,
                          std::vector<VkClearValue> const & clear_values,
                          VkSubpassContents                 subpass_contents );

};


#endif //VKCOOKBOOK_S08_BEGINNING_A_RENDER_PASS_H

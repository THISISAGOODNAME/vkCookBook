//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  08 Beginning a render pass

#include "S08_Beginning_a_render_pass.h"

namespace VKCookbook {

    void BeginRenderPass( VkCommandBuffer                   command_buffer,
                          VkRenderPass                      render_pass,
                          VkFramebuffer                     framebuffer,
                          VkRect2D                          render_area,
                          std::vector<VkClearValue> const & clear_values,
                          VkSubpassContents                 subpass_contents ) {
        VkRenderPassBeginInfo render_pass_begin_info = {
                VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,     // VkStructureType        sType
                nullptr,                                      // const void           * pNext
                render_pass,                                  // VkRenderPass           renderPass
                framebuffer,                                  // VkFramebuffer          framebuffer
                render_area,                                  // VkRect2D               renderArea
                static_cast<uint32_t>(clear_values.size()),   // uint32_t               clearValueCount
                clear_values.data()                           // const VkClearValue   * pClearValues
        };

        vkCmdBeginRenderPass( command_buffer, &render_pass_begin_info, subpass_contents );
    }

}
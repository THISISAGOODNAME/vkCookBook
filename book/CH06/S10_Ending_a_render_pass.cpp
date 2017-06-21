//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  10 Ending a render pass

#include "S10_Ending_a_render_pass.h"

namespace VKCookbook {

    void EndRenderPass( VkCommandBuffer command_buffer ) {
        vkCmdEndRenderPass( command_buffer );
    }

}
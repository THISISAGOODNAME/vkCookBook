//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  09 Progressing to the next subpass

#include "S09_Progressing_to_the_next_subpass.h"

namespace VKCookbook {

    void ProgressToTheNextSubpass( VkCommandBuffer   command_buffer,
                                   VkSubpassContents subpass_contents ) {
        vkCmdNextSubpass( command_buffer, subpass_contents );
    }

}
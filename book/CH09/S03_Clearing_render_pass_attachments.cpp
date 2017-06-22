//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  03 Clearing render pass attachments

#include "S03_Clearing_render_pass_attachments.h"

namespace VKCookbook {

    void ClearRenderPassAttachments( VkCommandBuffer                        command_buffer,
                                     std::vector<VkClearAttachment> const & attachments,
                                     std::vector<VkClearRect> const       & rects ){
        vkCmdClearAttachments( command_buffer, static_cast<uint32_t>(attachments.size()), attachments.data(), static_cast<uint32_t>(rects.size()), rects.data() );
    }

}
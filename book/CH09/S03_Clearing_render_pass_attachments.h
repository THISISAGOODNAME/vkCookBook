//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  03 Clearing render pass attachments

#ifndef VKCOOKBOOK_S03_CLEARING_RENDER_PASS_ATTACHMENTS_H
#define VKCOOKBOOK_S03_CLEARING_RENDER_PASS_ATTACHMENTS_H

#include "Common.h"

namespace VKCookbook {

    void ClearRenderPassAttachments( VkCommandBuffer                        command_buffer,
                                     std::vector<VkClearAttachment> const & attachments,
                                     std::vector<VkClearRect> const       & rects );

};


#endif //VKCOOKBOOK_S03_CLEARING_RENDER_PASS_ATTACHMENTS_H

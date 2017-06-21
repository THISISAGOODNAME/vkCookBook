//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  05 Creating a framebuffer

#ifndef VKCOOKBOOK_S05_CREATING_A_FRAMEBUFFER_H
#define VKCOOKBOOK_S05_CREATING_A_FRAMEBUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool CreateFramebuffer( VkDevice                         logical_device,
                            VkRenderPass                     render_pass,
                            std::vector<VkImageView> const & attachments,
                            uint32_t                         width,
                            uint32_t                         height,
                            uint32_t                         layers,
                            VkFramebuffer                  & framebuffer );

};


#endif //VKCOOKBOOK_S05_CREATING_A_FRAMEBUFFER_H

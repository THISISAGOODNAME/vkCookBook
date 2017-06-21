//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  04 Creating a render pass

#ifndef VKCOOKBOOK_S04_CREATING_A_RENDER_PASS_H
#define VKCOOKBOOK_S04_CREATING_A_RENDER_PASS_H

#include "Common.h"
#include "S02_Specifying_subpass_descriptions.h"

namespace VKCookbook {

    bool CreateRenderPass( VkDevice                                     logical_device,
                           std::vector<VkAttachmentDescription> const & attachments_descriptions,
                           std::vector<SubpassParameters> const       & subpass_parameters,
                           std::vector<VkSubpassDependency> const     & subpass_dependencies,
                           VkRenderPass                               & render_pass );

};


#endif //VKCOOKBOOK_S04_CREATING_A_RENDER_PASS_H

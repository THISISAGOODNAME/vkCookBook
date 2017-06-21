//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  02 Specifying subpass descriptions

#ifndef VKCOOKBOOK_S02_SPECIFYING_SUBPASS_DESCRIPTIONS_H
#define VKCOOKBOOK_S02_SPECIFYING_SUBPASS_DESCRIPTIONS_H

#include "Common.h"

namespace VKCookbook {

    struct SubpassParameters {
        VkPipelineBindPoint                  PipelineType;
        std::vector<VkAttachmentReference>   InputAttachments;
        std::vector<VkAttachmentReference>   ColorAttachments;
        std::vector<VkAttachmentReference>   ResolveAttachments;
        VkAttachmentReference const        * DepthStencilAttachment;
        std::vector<uint32_t>                PreserveAttachments;
    };

    void SpecifySubpassDescriptions( std::vector<SubpassParameters> const & subpass_parameters,
                                     std::vector<VkSubpassDescription>    & subpass_descriptions );

};


#endif //VKCOOKBOOK_S02_SPECIFYING_SUBPASS_DESCRIPTIONS_H

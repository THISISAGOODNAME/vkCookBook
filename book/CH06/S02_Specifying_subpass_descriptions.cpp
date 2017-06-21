//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  02 Specifying subpass descriptions

#include "S02_Specifying_subpass_descriptions.h"

namespace VKCookbook {

    void SpecifySubpassDescriptions( std::vector<SubpassParameters> const & subpass_parameters,
                                     std::vector<VkSubpassDescription>    & subpass_descriptions ) {
        subpass_descriptions.clear();

        for( auto & subpass_description : subpass_parameters ) {
            subpass_descriptions.push_back( {
                                                    0,                                                                      // VkSubpassDescriptionFlags        flags
                                                    subpass_description.PipelineType,                                       // VkPipelineBindPoint              pipelineBindPoint
                                                    static_cast<uint32_t>(subpass_description.InputAttachments.size()),     // uint32_t                         inputAttachmentCount
                                                    subpass_description.InputAttachments.data(),                            // const VkAttachmentReference    * pInputAttachments
                                                    static_cast<uint32_t>(subpass_description.ColorAttachments.size()),     // uint32_t                         colorAttachmentCount
                                                    subpass_description.ColorAttachments.data(),                            // const VkAttachmentReference    * pColorAttachments
                                                    subpass_description.ResolveAttachments.data(),                          // const VkAttachmentReference    * pResolveAttachments
                                                    subpass_description.DepthStencilAttachment,                             // const VkAttachmentReference    * pDepthStencilAttachment
                                                    static_cast<uint32_t>(subpass_description.PreserveAttachments.size()),  // uint32_t                         preserveAttachmentCount
                                                    subpass_description.PreserveAttachments.data()                          // const uint32_t                 * pPreserveAttachments
                                            } );
        }
    }

}

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  04 Creating a render pass

#include "S01_Specifying_attachments_descriptions.h"
#include "S02_Specifying_subpass_descriptions.h"
#include "S03_Specifying_dependencies_between_subpasses.h"
#include "S04_Creating_a_render_pass.h"

namespace VKCookbook {

    bool CreateRenderPass( VkDevice                                     logical_device,
                           std::vector<VkAttachmentDescription> const & attachments_descriptions,
                           std::vector<SubpassParameters> const       & subpass_parameters,
                           std::vector<VkSubpassDependency> const     & subpass_dependencies,
                           VkRenderPass                               & render_pass ) {
        SpecifyAttachmentsDescriptions( attachments_descriptions );

        std::vector<VkSubpassDescription> subpass_descriptions;
        SpecifySubpassDescriptions( subpass_parameters, subpass_descriptions );

        SpecifyDependenciesBetweenSubpasses( subpass_dependencies );

        VkRenderPassCreateInfo render_pass_create_info = {
                VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,                // VkStructureType                    sType
                nullptr,                                                  // const void                       * pNext
                0,                                                        // VkRenderPassCreateFlags            flags
                static_cast<uint32_t>(attachments_descriptions.size()),   // uint32_t                           attachmentCount
                attachments_descriptions.data(),                          // const VkAttachmentDescription    * pAttachments
                static_cast<uint32_t>(subpass_descriptions.size()),       // uint32_t                           subpassCount
                subpass_descriptions.data(),                              // const VkSubpassDescription       * pSubpasses
                static_cast<uint32_t>(subpass_dependencies.size()),       // uint32_t                           dependencyCount
                subpass_dependencies.data()                               // const VkSubpassDependency        * pDependencies
        };

        VkResult result = vkCreateRenderPass( logical_device, &render_pass_create_info, nullptr, &render_pass );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create a render pass." << std::endl;
            return false;
        }
        return true;
    }

}
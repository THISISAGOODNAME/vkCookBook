//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  05 Creating a framebuffer

#include "S05_Creating_a_framebuffer.h"

namespace VKCookbook {

    bool CreateFramebuffer( VkDevice                         logical_device,
                            VkRenderPass                     render_pass,
                            std::vector<VkImageView> const & attachments,
                            uint32_t                         width,
                            uint32_t                         height,
                            uint32_t                         layers,
                            VkFramebuffer                  & framebuffer ) {
        VkFramebufferCreateInfo framebuffer_create_info = {
                VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,    // VkStructureType              sType
                nullptr,                                      // const void                 * pNext
                0,                                            // VkFramebufferCreateFlags     flags
                render_pass,                                  // VkRenderPass                 renderPass
                static_cast<uint32_t>(attachments.size()),    // uint32_t                     attachmentCount
                attachments.data(),                           // const VkImageView          * pAttachments
                width,                                        // uint32_t                     width
                height,                                       // uint32_t                     height
                layers                                        // uint32_t                     layers
        };

        VkResult result = vkCreateFramebuffer( logical_device, &framebuffer_create_info, nullptr, &framebuffer );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create a framebuffer." << std::endl;
            return false;
        }
        return true;
    }

}
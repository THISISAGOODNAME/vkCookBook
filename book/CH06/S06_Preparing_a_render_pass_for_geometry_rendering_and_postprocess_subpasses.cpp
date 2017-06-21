//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  06 Preparing a render pass for geometry rendering and postprocess subpasses

#include "S04_Creating_a_render_pass.h"
#include "S06_Preparing_a_render_pass_for_geometry_rendering_and_postprocess_subpasses.h"

namespace VKCookbook {

    bool PrepareRenderPassForGeometryRenderingAndPostprocessSubpasses( VkDevice     logical_device,
                                                                       VkRenderPass render_pass ) {
        std::vector<VkAttachmentDescription> attachments_descriptions = {
                {
                        0,                                                // VkAttachmentDescriptionFlags     flags
                        VK_FORMAT_R8G8B8A8_UNORM,                         // VkFormat                         format
                        VK_SAMPLE_COUNT_1_BIT,                            // VkSampleCountFlagBits            samples
                        VK_ATTACHMENT_LOAD_OP_CLEAR,                      // VkAttachmentLoadOp               loadOp
                        VK_ATTACHMENT_STORE_OP_DONT_CARE,                 // VkAttachmentStoreOp              storeOp
                        VK_ATTACHMENT_LOAD_OP_DONT_CARE,                  // VkAttachmentLoadOp               stencilLoadOp
                        VK_ATTACHMENT_STORE_OP_DONT_CARE,                 // VkAttachmentStoreOp              stencilStoreOp
                        VK_IMAGE_LAYOUT_UNDEFINED,                        // VkImageLayout                    initialLayout
                        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,         // VkImageLayout                    finalLayout
                },
                {
                        0,                                                // VkAttachmentDescriptionFlags     flags
                        VK_FORMAT_D16_UNORM,                              // VkFormat                         format
                        VK_SAMPLE_COUNT_1_BIT,                            // VkSampleCountFlagBits            samples
                        VK_ATTACHMENT_LOAD_OP_CLEAR,                      // VkAttachmentLoadOp               loadOp
                        VK_ATTACHMENT_STORE_OP_DONT_CARE,                 // VkAttachmentStoreOp              storeOp
                        VK_ATTACHMENT_LOAD_OP_DONT_CARE,                  // VkAttachmentLoadOp               stencilLoadOp
                        VK_ATTACHMENT_STORE_OP_DONT_CARE,                 // VkAttachmentStoreOp              stencilStoreOp
                        VK_IMAGE_LAYOUT_UNDEFINED,                        // VkImageLayout                    initialLayout
                        VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL, // VkImageLayout                    finalLayout
                },
                {
                        0,                                                // VkAttachmentDescriptionFlags     flags
                        VK_FORMAT_R8G8B8A8_UNORM,                         // VkFormat                         format
                        VK_SAMPLE_COUNT_1_BIT,                            // VkSampleCountFlagBits            samples
                        VK_ATTACHMENT_LOAD_OP_CLEAR,                      // VkAttachmentLoadOp               loadOp
                        VK_ATTACHMENT_STORE_OP_STORE,                     // VkAttachmentStoreOp              storeOp
                        VK_ATTACHMENT_LOAD_OP_DONT_CARE,                  // VkAttachmentLoadOp               stencilLoadOp
                        VK_ATTACHMENT_STORE_OP_DONT_CARE,                 // VkAttachmentStoreOp              stencilStoreOp
                        VK_IMAGE_LAYOUT_UNDEFINED,                        // VkImageLayout                    initialLayout
                        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,                  // VkImageLayout                    finalLayout
                },
        };

        VkAttachmentReference depth_stencil_attachment = {
                1,                                                  // uint32_t                             attachment
                VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,   // VkImageLayout                        layout
        };

        std::vector<SubpassParameters> subpass_parameters = {
                // #0 subpass
                {
                        VK_PIPELINE_BIND_POINT_GRAPHICS,                  // VkPipelineBindPoint                  PipelineType
                        {},                                               // std::vector<VkAttachmentReference>   InputAttachments
                        {                                                 // std::vector<VkAttachmentReference>   ColorAttachments
                                {
                                        0,                                              // uint32_t                             attachment
                                        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL        // VkImageLayout                        layout
                                }
                        },
                        {},                                               // std::vector<VkAttachmentReference>   ResolveAttachments
                        &depth_stencil_attachment,                        // const VkAttachmentReference        * DepthStencilAttachment
                        {}                                                // std::vector<uint32_t>                PreserveAttachments
                },
                // #1 subpass
                {
                        VK_PIPELINE_BIND_POINT_GRAPHICS,                  // VkPipelineBindPoint                  PipelineType
                        {                                                 // std::vector<VkAttachmentReference>   InputAttachments
                                {
                                        0,                                              // uint32_t                             attachment
                                        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL        // VkImageLayout                        layout
                                }
                        },
                        {                                                 // std::vector<VkAttachmentReference>   ColorAttachments
                                {
                                        2,                                              // uint32_t                             attachment
                                        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL        // VkImageLayout                        layout
                                }
                        },
                        {},                                               // std::vector<VkAttachmentReference>   ResolveAttachments
                        nullptr,                                          // const VkAttachmentReference        * DepthStencilAttachment
                        {}                                                // std::vector<uint32_t>                PreserveAttachments
                }
        };

        std::vector<VkSubpassDependency> subpass_dependencies = {
                {
                        0,                                              // uint32_t                 srcSubpass
                        1,                                              // uint32_t                 dstSubpass
                        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,  // VkPipelineStageFlags     srcStageMask
                        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,          // VkPipelineStageFlags     dstStageMask
                        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,           // VkAccessFlags            srcAccessMask
                        VK_ACCESS_INPUT_ATTACHMENT_READ_BIT,            // VkAccessFlags            dstAccessMask
                        VK_DEPENDENCY_BY_REGION_BIT                     // VkDependencyFlags        dependencyFlags
                }
        };

        if( !CreateRenderPass( logical_device, attachments_descriptions, subpass_parameters, subpass_dependencies, render_pass ) ) {
            return false;
        }
        return true;
    }

}
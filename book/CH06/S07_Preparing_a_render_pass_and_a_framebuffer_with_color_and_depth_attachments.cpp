//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  07 Preparing a render pass and a framebuffer with color and depth attachments

#include "../CH04/S09_Creating_a_2D_image_and_view.h"
#include "S04_Creating_a_render_pass.h"
#include "S05_Creating_a_framebuffer.h"
#include "S07_Preparing_a_render_pass_and_a_framebuffer_with_color_and_depth_attachments.h"

namespace VKCookbook {

    bool PrepareRenderPassAndFramebufferWithColorAndDepthAttachments( VkPhysicalDevice        physical_device,
                                                                      VkDevice                logical_device,
                                                                      uint32_t                width,
                                                                      uint32_t                height,
                                                                      VkImage               & color_image,
                                                                      VkDeviceMemory        & color_image_memory_object,
                                                                      VkImageView           & color_image_view,
                                                                      VkImage               & depth_image,
                                                                      VkDeviceMemory        & depth_image_memory_object,
                                                                      VkImageView           & depth_image_view,
                                                                      VkRenderPass          & render_pass,
                                                                      VkFramebuffer         & framebuffer ) {
        if( !Create2DImageAndView( physical_device, logical_device, VK_FORMAT_R8G8B8A8_UNORM, { width, height }, 1, 1, VK_SAMPLE_COUNT_1_BIT,
                                   VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_IMAGE_ASPECT_COLOR_BIT, color_image, color_image_memory_object, color_image_view ) ) {
            return false;
        }

        if( !Create2DImageAndView( physical_device, logical_device, VK_FORMAT_D16_UNORM, { width, height }, 1, 1, VK_SAMPLE_COUNT_1_BIT,
                                   VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT, VK_IMAGE_ASPECT_DEPTH_BIT, depth_image, depth_image_memory_object, depth_image_view ) ) {
            return false;
        }

        std::vector<VkAttachmentDescription> attachments_descriptions = {
                {
                        0,                                                // VkAttachmentDescriptionFlags     flags
                        VK_FORMAT_R8G8B8A8_UNORM,                         // VkFormat                         format
                        VK_SAMPLE_COUNT_1_BIT,                            // VkSampleCountFlagBits            samples
                        VK_ATTACHMENT_LOAD_OP_CLEAR,                      // VkAttachmentLoadOp               loadOp
                        VK_ATTACHMENT_STORE_OP_STORE,                     // VkAttachmentStoreOp              storeOp
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
                        VK_ATTACHMENT_STORE_OP_STORE,                     // VkAttachmentStoreOp              storeOp
                        VK_ATTACHMENT_LOAD_OP_DONT_CARE,                  // VkAttachmentLoadOp               stencilLoadOp
                        VK_ATTACHMENT_STORE_OP_DONT_CARE,                 // VkAttachmentStoreOp              stencilStoreOp
                        VK_IMAGE_LAYOUT_UNDEFINED,                        // VkImageLayout                    initialLayout
                        VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL,  // VkImageLayout                    finalLayout
                }
        };

        VkAttachmentReference depth_stencil_attachment = {
                1,                                                  // uint32_t                             attachment
                VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,   // VkImageLayout                        layout
        };

        std::vector<SubpassParameters> subpass_parameters = {
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
                }
        };

        std::vector<VkSubpassDependency> subpass_dependencies = {
                {
                        0,                                                // uint32_t                 srcSubpass
                        VK_SUBPASS_EXTERNAL,                              // uint32_t                 dstSubpass
                        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,    // VkPipelineStageFlags     srcStageMask
                        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,            // VkPipelineStageFlags     dstStageMask
                        VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,             // VkAccessFlags            srcAccessMask
                        VK_ACCESS_SHADER_READ_BIT,                        // VkAccessFlags            dstAccessMask
                        0                                                 // VkDependencyFlags        dependencyFlags
                }
        };

        if( !CreateRenderPass( logical_device, attachments_descriptions, subpass_parameters, subpass_dependencies, render_pass ) ) {
            return false;
        }

        if( !CreateFramebuffer( logical_device, render_pass, { color_image_view, depth_image_view }, width, height, 1, framebuffer ) ) {
            return false;
        }
        return true;
    }

}
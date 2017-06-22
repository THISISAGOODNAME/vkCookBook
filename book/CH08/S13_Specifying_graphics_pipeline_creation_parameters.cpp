//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  13 Specifying graphics pipeline creation parameters

#include "S13_Specifying_graphics_pipeline_creation_parameters.h"

namespace VKCookbook {

    void SpecifyGraphicsPipelineCreationParameters( VkPipelineCreateFlags                                additional_options,
                                                    std::vector<VkPipelineShaderStageCreateInfo> const & shader_stage_create_infos,
                                                    VkPipelineVertexInputStateCreateInfo const         & vertex_input_state_create_info,
                                                    VkPipelineInputAssemblyStateCreateInfo const       & input_assembly_state_create_info,
                                                    VkPipelineTessellationStateCreateInfo const        * tessellation_state_create_info,
                                                    VkPipelineViewportStateCreateInfo const            * viewport_state_create_info,
                                                    VkPipelineRasterizationStateCreateInfo const       & rasterization_state_create_info,
                                                    VkPipelineMultisampleStateCreateInfo const         * multisample_state_create_info,
                                                    VkPipelineDepthStencilStateCreateInfo const        * depth_and_stencil_state_create_info,
                                                    VkPipelineColorBlendStateCreateInfo const          * blend_state_create_info,
                                                    VkPipelineDynamicStateCreateInfo const             * dynamic_state_creat_info,
                                                    VkPipelineLayout                                     pipeline_layout,
                                                    VkRenderPass                                         render_pass,
                                                    uint32_t                                             subpass,
                                                    VkPipeline                                           base_pipeline_handle,
                                                    int32_t                                              base_pipeline_index,
                                                    VkGraphicsPipelineCreateInfo                       & graphics_pipeline_create_info ){
        graphics_pipeline_create_info = {
                VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,            // VkStructureType                                sType
                nullptr,                                                    // const void                                   * pNext
                additional_options,                                         // VkPipelineCreateFlags                          flags
                static_cast<uint32_t>(shader_stage_create_infos.size()),    // uint32_t                                       stageCount
                shader_stage_create_infos.data(),                           // const VkPipelineShaderStageCreateInfo        * pStages
                &vertex_input_state_create_info,                            // const VkPipelineVertexInputStateCreateInfo   * pVertexInputState
                &input_assembly_state_create_info,                          // const VkPipelineInputAssemblyStateCreateInfo * pInputAssemblyState
                tessellation_state_create_info,                             // const VkPipelineTessellationStateCreateInfo  * pTessellationState
                viewport_state_create_info,                                 // const VkPipelineViewportStateCreateInfo      * pViewportState
                &rasterization_state_create_info,                           // const VkPipelineRasterizationStateCreateInfo * pRasterizationState
                multisample_state_create_info,                              // const VkPipelineMultisampleStateCreateInfo   * pMultisampleState
                depth_and_stencil_state_create_info,                        // const VkPipelineDepthStencilStateCreateInfo  * pDepthStencilState
                blend_state_create_info,                                    // const VkPipelineColorBlendStateCreateInfo    * pColorBlendState
                dynamic_state_creat_info,                                   // const VkPipelineDynamicStateCreateInfo       * pDynamicState
                pipeline_layout,                                            // VkPipelineLayout                               layout
                render_pass,                                                // VkRenderPass                                   renderPass
                subpass,                                                    // uint32_t                                       subpass
                base_pipeline_handle,                                       // VkPipeline                                     basePipelineHandle
                base_pipeline_index                                         // int32_t                                        basePipelineIndex
        };
    }

}
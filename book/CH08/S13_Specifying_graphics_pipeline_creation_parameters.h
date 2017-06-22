//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  13 Specifying graphics pipeline creation parameters

#ifndef VKCOOKBOOK_S13_SPECIFYING_GRAPHICS_PIPELINE_CREATION_PARAMETERS_H
#define VKCOOKBOOK_S13_SPECIFYING_GRAPHICS_PIPELINE_CREATION_PARAMETERS_H

#include "Common.h"

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
                                                    VkGraphicsPipelineCreateInfo                       & graphics_pipeline_create_info );

};


#endif //VKCOOKBOOK_S13_SPECIFYING_GRAPHICS_PIPELINE_CREATION_PARAMETERS_H

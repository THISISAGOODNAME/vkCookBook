//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  21 Creating a graphics pipeline with vertex and fragment shaders, depth test enabled, and with dynamic viewport and scissor tests

#ifndef VKCOOKBOOK_S21_CREATING_A_GRAPHICS_PIPELINE_WITH_VERTEX_AND_FRAGMENT_SHADERS_DEPTH_TEST_ENABLED_AND_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_TESTS_H
#define VKCOOKBOOK_S21_CREATING_A_GRAPHICS_PIPELINE_WITH_VERTEX_AND_FRAGMENT_SHADERS_DEPTH_TEST_ENABLED_AND_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_TESTS_H

#include "Common.h"

namespace VKCookbook {

    bool CreateGraphicsPipelineWithVertexAndFragmentShadersDepthTestEnabledAndWithDynamicViewportAndScissorTests( VkDevice                                                 logical_device,
                                                                                                                  VkPipelineCreateFlags                                    additional_options,
                                                                                                                  std::string const                                      & vertex_shader_filename,
                                                                                                                  std::string const                                      & fragment_shader_filename,
                                                                                                                  std::vector<VkVertexInputBindingDescription> const     & vertex_input_binding_descriptions,
                                                                                                                  std::vector<VkVertexInputAttributeDescription> const   & vertex_attribute_descriptions,
                                                                                                                  VkPrimitiveTopology                                      primitive_topology,
                                                                                                                  bool                                                     primitive_restart_enable,
                                                                                                                  VkPolygonMode                                            polygon_mode,
                                                                                                                  VkCullModeFlags                                          culling_mode,
                                                                                                                  VkFrontFace                                              front_face,
                                                                                                                  bool                                                     logic_op_enable,
                                                                                                                  VkLogicOp                                                logic_op,
                                                                                                                  std::vector<VkPipelineColorBlendAttachmentState> const & attachment_blend_states,
                                                                                                                  std::array<float, 4> const                             & blend_constants,
                                                                                                                  VkPipelineLayout                                         pipeline_layout,
                                                                                                                  VkRenderPass                                             render_pass,
                                                                                                                  uint32_t                                                 subpass,
                                                                                                                  VkPipeline                                               base_pipeline_handle,
                                                                                                                  VkPipelineCache                                          pipeline_cache,
                                                                                                                  std::vector<VkPipeline>                                & graphics_pipeline );

};


#endif //VKCOOKBOOK_S21_CREATING_A_GRAPHICS_PIPELINE_WITH_VERTEX_AND_FRAGMENT_SHADERS_DEPTH_TEST_ENABLED_AND_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_TESTS_H

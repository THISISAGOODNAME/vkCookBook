//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  07 Specifying pipeline rasterization state

#include "S07_Specifying_pipeline_rasterization_state.h"

namespace VKCookbook {

    void SpecifyPipelineRasterizationState( bool                                     depth_clamp_enable,
                                            bool                                     rasterizer_discard_enable,
                                            VkPolygonMode                            polygon_mode,
                                            VkCullModeFlags                          culling_mode,
                                            VkFrontFace                              front_face,
                                            bool                                     depth_bias_enable,
                                            float                                    depth_bias_constant_factor,
                                            float                                    depth_bias_clamp,
                                            float                                    depth_bias_slope_factor,
                                            float                                    line_width,
                                            VkPipelineRasterizationStateCreateInfo & rasterization_state_create_info ){
        rasterization_state_create_info = {
                VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO, // VkStructureType                            sType
                nullptr,                                                    // const void                               * pNext
                0,                                                          // VkPipelineRasterizationStateCreateFlags    flags
                depth_clamp_enable,                                         // VkBool32                                   depthClampEnable
                rasterizer_discard_enable,                                  // VkBool32                                   rasterizerDiscardEnable
                polygon_mode,                                               // VkPolygonMode                              polygonMode
                culling_mode,                                               // VkCullModeFlags                            cullMode
                front_face,                                                 // VkFrontFace                                frontFace
                depth_bias_enable,                                          // VkBool32                                   depthBiasEnable
                depth_bias_constant_factor,                                 // float                                      depthBiasConstantFactor
                depth_bias_clamp,                                           // float                                      depthBiasClamp
                depth_bias_slope_factor,                                    // float                                      depthBiasSlopeFactor
                line_width                                                  // float                                      lineWidth
        };
    }

}
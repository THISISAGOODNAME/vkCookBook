//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  07 Specifying pipeline rasterization state

#ifndef VKCOOKBOOK_S07_SPECIFYING_PIPELINE_RASTERIZATION_STATE_H
#define VKCOOKBOOK_S07_SPECIFYING_PIPELINE_RASTERIZATION_STATE_H

#include "Common.h"

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
                                            VkPipelineRasterizationStateCreateInfo & rasterization_state_create_info );

};


#endif //VKCOOKBOOK_S07_SPECIFYING_PIPELINE_RASTERIZATION_STATE_H

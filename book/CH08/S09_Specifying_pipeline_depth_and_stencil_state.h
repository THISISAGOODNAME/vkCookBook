//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  09 Specifying pipeline depth and stencil state

#ifndef VKCOOKBOOK_S09_SPECIFYING_PIPELINE_DEPTH_AND_STENCIL_STATE_H
#define VKCOOKBOOK_S09_SPECIFYING_PIPELINE_DEPTH_AND_STENCIL_STATE_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyPipelineDepthAndStencilState( bool                                    depth_test_enable,
                                              bool                                    depth_write_enable,
                                              VkCompareOp                             depth_compare_op,
                                              bool                                    depth_bounds_test_enable,
                                              float                                   min_depth_bounds,
                                              float                                   max_depth_bounds,
                                              bool                                    stencil_test_enable,
                                              VkStencilOpState                        front_stencil_test_parameters,
                                              VkStencilOpState                        back_stencil_test_parameters,
                                              VkPipelineDepthStencilStateCreateInfo & depth_and_stencil_state_create_info );

};


#endif //VKCOOKBOOK_S09_SPECIFYING_PIPELINE_DEPTH_AND_STENCIL_STATE_H

//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  09 Specifying pipeline depth and stencil state

#include "S09_Specifying_pipeline_depth_and_stencil_state.h"

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
                                              VkPipelineDepthStencilStateCreateInfo & depth_and_stencil_state_create_info ){
        depth_and_stencil_state_create_info = {
                VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO,   // VkStructureType                            sType
                nullptr,                                                      // const void                               * pNext
                0,                                                            // VkPipelineDepthStencilStateCreateFlags     flags
                depth_test_enable,                                            // VkBool32                                   depthTestEnable
                depth_write_enable,                                           // VkBool32                                   depthWriteEnable
                depth_compare_op,                                             // VkCompareOp                                depthCompareOp
                depth_bounds_test_enable,                                     // VkBool32                                   depthBoundsTestEnable
                stencil_test_enable,                                          // VkBool32                                   stencilTestEnable
                front_stencil_test_parameters,                                // VkStencilOpState                           front
                back_stencil_test_parameters,                                 // VkStencilOpState                           back
                min_depth_bounds,                                             // float                                      minDepthBounds
                max_depth_bounds                                              // float                                      maxDepthBounds
        };
    }

}
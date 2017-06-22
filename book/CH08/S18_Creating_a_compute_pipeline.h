//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  18 Creating a compute pipeline

#ifndef VKCOOKBOOK_S18_CREATING_A_COMPUTE_PIPELINE_H
#define VKCOOKBOOK_S18_CREATING_A_COMPUTE_PIPELINE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateComputePipeline( VkDevice                                logical_device,
                                VkPipelineCreateFlags                   additional_options,
                                VkPipelineShaderStageCreateInfo const & compute_shader_stage,
                                VkPipelineLayout                        pipeline_layout,
                                VkPipeline                              base_pipeline_handle,
                                VkPipelineCache                         pipeline_cache,
                                VkPipeline                            & compute_pipeline );

};


#endif //VKCOOKBOOK_S18_CREATING_A_COMPUTE_PIPELINE_H

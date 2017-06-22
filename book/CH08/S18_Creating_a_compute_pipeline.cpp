//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  18 Creating a compute pipeline

#include "S18_Creating_a_compute_pipeline.h"

namespace VKCookbook {

    bool CreateComputePipeline( VkDevice                                logical_device,
                                VkPipelineCreateFlags                   additional_options,
                                VkPipelineShaderStageCreateInfo const & compute_shader_stage,
                                VkPipelineLayout                        pipeline_layout,
                                VkPipeline                              base_pipeline_handle,
                                VkPipelineCache                         pipeline_cache,
                                VkPipeline                            & compute_pipeline ){
        VkComputePipelineCreateInfo compute_pipeline_create_info = {
                VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO,   // VkStructureType                    sType
                nullptr,                                          // const void                       * pNext
                additional_options,                               // VkPipelineCreateFlags              flags
                compute_shader_stage,                             // VkPipelineShaderStageCreateInfo    stage
                pipeline_layout,                                  // VkPipelineLayout                   layout
                base_pipeline_handle,                             // VkPipeline                         basePipelineHandle
                -1                                                // int32_t                            basePipelineIndex
        };

        VkResult result = vkCreateComputePipelines( logical_device, pipeline_cache, 1, &compute_pipeline_create_info, nullptr, &compute_pipeline );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create compute pipeline." << std::endl;
            return false;
        }
        return true;
    }

}
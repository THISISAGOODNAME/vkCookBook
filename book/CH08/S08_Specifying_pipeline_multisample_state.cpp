//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  08 Specifying pipeline multisample state

#include "S08_Specifying_pipeline_multisample_state.h"

namespace VKCookbook {

    void SpecifyPipelineMultisampleState( VkSampleCountFlagBits                  sample_count,
                                          bool                                   per_sample_shading_enable,
                                          float                                  min_sample_shading,
                                          VkSampleMask const                   * sample_masks,
                                          bool                                   alpha_to_coverage_enable,
                                          bool                                   alpha_to_one_enable,
                                          VkPipelineMultisampleStateCreateInfo & multisample_state_create_info ){
        multisample_state_create_info = {
                VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO, // VkStructureType                          sType
                nullptr,                                                  // const void                             * pNext
                0,                                                        // VkPipelineMultisampleStateCreateFlags    flags
                sample_count,                                             // VkSampleCountFlagBits                    rasterizationSamples
                per_sample_shading_enable,                                // VkBool32                                 sampleShadingEnable
                min_sample_shading,                                       // float                                    minSampleShading
                sample_masks,                                             // const VkSampleMask                     * pSampleMask
                alpha_to_coverage_enable,                                 // VkBool32                                 alphaToCoverageEnable
                alpha_to_one_enable                                       // VkBool32                                 alphaToOneEnable
        };
    }

}
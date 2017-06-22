//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  20 Creating a pipeline layout with a combined image sampler, a buffer and push constant ranges

#ifndef VKCOOKBOOK_S20_CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES_H
#define VKCOOKBOOK_S20_CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES_H

#include "Common.h"

namespace VKCookbook {

    bool CreatePipelineLayoutWithCombinedImageSamplerBufferAndPushConstantRanges( VkDevice                                 logical_device,
                                                                                  std::vector<VkPushConstantRange> const & push_constant_ranges,
                                                                                  VkDescriptorSetLayout                  & descriptor_set_layout,
                                                                                  VkPipelineLayout                       & pipeline_layout );

};


#endif //VKCOOKBOOK_S20_CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES_H

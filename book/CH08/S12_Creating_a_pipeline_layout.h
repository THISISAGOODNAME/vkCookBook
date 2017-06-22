//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  12 Creating a pipeline layout

#ifndef VKCOOKBOOK_S12_CREATING_A_PIPELINE_LAYOUT_H
#define VKCOOKBOOK_S12_CREATING_A_PIPELINE_LAYOUT_H

#include "Common.h"

namespace VKCookbook {

    bool CreatePipelineLayout( VkDevice                                   logical_device,
                               std::vector<VkDescriptorSetLayout> const & descriptor_set_layouts,
                               std::vector<VkPushConstantRange> const   & push_constant_ranges,
                               VkPipelineLayout                         & pipeline_layout );

};


#endif //VKCOOKBOOK_S12_CREATING_A_PIPELINE_LAYOUT_H

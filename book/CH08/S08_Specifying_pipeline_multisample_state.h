//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  08 Specifying pipeline multisample state

#ifndef VKCOOKBOOK_S08_SPECIFYING_PIPELINE_MULTISAMPLE_STATE_H
#define VKCOOKBOOK_S08_SPECIFYING_PIPELINE_MULTISAMPLE_STATE_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyPipelineMultisampleState( VkSampleCountFlagBits                  sample_count,
                                          bool                                   per_sample_shading_enable,
                                          float                                  min_sample_shading,
                                          VkSampleMask const                   * sample_masks,
                                          bool                                   alpha_to_coverage_enable,
                                          bool                                   alpha_to_one_enable,
                                          VkPipelineMultisampleStateCreateInfo & multisample_state_create_info );

};


#endif //VKCOOKBOOK_S08_SPECIFYING_PIPELINE_MULTISAMPLE_STATE_H

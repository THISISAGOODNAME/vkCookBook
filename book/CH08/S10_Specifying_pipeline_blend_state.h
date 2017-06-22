//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  10 Specifying pipeline blend state

#ifndef VKCOOKBOOK_S10_SPECIFYING_PIPELINE_BLEND_STATE_H
#define VKCOOKBOOK_S10_SPECIFYING_PIPELINE_BLEND_STATE_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyPipelineBlendState( bool                                                     logic_op_enable,
                                    VkLogicOp                                                logic_op,
                                    std::vector<VkPipelineColorBlendAttachmentState> const & attachment_blend_states,
                                    std::array<float, 4> const                             & blend_constants,
                                    VkPipelineColorBlendStateCreateInfo                    & blend_state_create_info );

};


#endif //VKCOOKBOOK_S10_SPECIFYING_PIPELINE_BLEND_STATE_H

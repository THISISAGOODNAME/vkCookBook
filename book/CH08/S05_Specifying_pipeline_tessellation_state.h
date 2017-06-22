//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  05 Specifying pipeline tessellation state

#ifndef VKCOOKBOOK_S05_SPECIFYING_PIPELINE_TESSELLATION_STATE_H
#define VKCOOKBOOK_S05_SPECIFYING_PIPELINE_TESSELLATION_STATE_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyPipelineTessellationState( uint32_t                                patch_control_points_count,
                                           VkPipelineTessellationStateCreateInfo & tessellation_state_create_info );

};


#endif //VKCOOKBOOK_S05_SPECIFYING_PIPELINE_TESSELLATION_STATE_H

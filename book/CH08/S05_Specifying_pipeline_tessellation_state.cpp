//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  05 Specifying pipeline tessellation state

#include "S05_Specifying_pipeline_tessellation_state.h"

namespace VKCookbook {

    void SpecifyPipelineTessellationState( uint32_t                                patch_control_points_count,
                                           VkPipelineTessellationStateCreateInfo & tessellation_state_create_info ){
        tessellation_state_create_info = {
                VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO,    // VkStructureType                            sType
                nullptr,                                                      // const void                               * pNext
                0,                                                            // VkPipelineTessellationStateCreateFlags     flags
                patch_control_points_count                                    // uint32_t                                   patchControlPoints
        };
    }

}
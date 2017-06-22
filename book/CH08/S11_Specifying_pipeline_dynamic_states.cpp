//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  11 Specifying pipeline dynamic states

#include "S11_Specifying_pipeline_dynamic_states.h"

namespace VKCookbook {

    void SpecifyPipelineDynamicStates( std::vector<VkDynamicState> const & dynamic_states,
                                       VkPipelineDynamicStateCreateInfo  & dynamic_state_creat_info ){
        dynamic_state_creat_info = {
                VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO,     // VkStructureType                      sType
                nullptr,                                                  // const void                         * pNext
                0,                                                        // VkPipelineDynamicStateCreateFlags    flags
                static_cast<uint32_t>(dynamic_states.size()),             // uint32_t                             dynamicStateCount
                dynamic_states.data()                                     // const VkDynamicState               * pDynamicStates
        };
    }

}
//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  11 Specifying pipeline dynamic states

#ifndef VKCOOKBOOK_S11_SPECIFYING_PIPELINE_DYNAMIC_STATES_H
#define VKCOOKBOOK_S11_SPECIFYING_PIPELINE_DYNAMIC_STATES_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyPipelineDynamicStates( std::vector<VkDynamicState> const & dynamic_states,
                                       VkPipelineDynamicStateCreateInfo  & dynamic_state_creat_info );

};


#endif //VKCOOKBOOK_S11_SPECIFYING_PIPELINE_DYNAMIC_STATES_H

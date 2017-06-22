//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  04 Specifying pipeline input assembly state

#ifndef VKCOOKBOOK_S04_SPECIFYING_PIPELINE_INPUT_ASSEMBLY_STATE_H
#define VKCOOKBOOK_S04_SPECIFYING_PIPELINE_INPUT_ASSEMBLY_STATE_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyPipelineInputAssemblyState( VkPrimitiveTopology                      topology,
                                            bool                                     primitive_restart_enable,
                                            VkPipelineInputAssemblyStateCreateInfo & input_assembly_state_create_info );

};


#endif //VKCOOKBOOK_S04_SPECIFYING_PIPELINE_INPUT_ASSEMBLY_STATE_H

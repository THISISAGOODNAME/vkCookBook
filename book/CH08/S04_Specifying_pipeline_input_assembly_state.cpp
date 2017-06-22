//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  04 Specifying pipeline input assembly state

#include "S04_Specifying_pipeline_input_assembly_state.h"

namespace VKCookbook {

    void SpecifyPipelineInputAssemblyState( VkPrimitiveTopology                      topology,
                                            bool                                     primitive_restart_enable,
                                            VkPipelineInputAssemblyStateCreateInfo & input_assembly_state_create_info ) {
        input_assembly_state_create_info = {
                VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,  // VkStructureType                           sType
                nullptr,                                                      // const void                              * pNext
                0,                                                            // VkPipelineInputAssemblyStateCreateFlags   flags
                topology,                                                     // VkPrimitiveTopology                       topology
                primitive_restart_enable                                      // VkBool32                                  primitiveRestartEnable
        };
    }

}
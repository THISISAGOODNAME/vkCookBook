//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  10 Specifying pipeline blend state

#include "S10_Specifying_pipeline_blend_state.h"

namespace VKCookbook {

    void SpecifyPipelineBlendState( bool                                                     logic_op_enable,
                                    VkLogicOp                                                logic_op,
                                    std::vector<VkPipelineColorBlendAttachmentState> const & attachment_blend_states,
                                    std::array<float, 4> const                             & blend_constants,
                                    VkPipelineColorBlendStateCreateInfo                    & blend_state_create_info ){
        blend_state_create_info = {
                VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,   // VkStructureType                              sType
                nullptr,                                                    // const void                                 * pNext
                0,                                                          // VkPipelineColorBlendStateCreateFlags         flags
                logic_op_enable,                                            // VkBool32                                     logicOpEnable
                logic_op,                                                   // VkLogicOp                                    logicOp
                static_cast<uint32_t>(attachment_blend_states.size()),      // uint32_t                                     attachmentCount
                attachment_blend_states.data(),                             // const VkPipelineColorBlendAttachmentState  * pAttachments
                {                                                           // float                                        blendConstants[4]
                        blend_constants[0],
                        blend_constants[1],
                        blend_constants[2],
                        blend_constants[3]
                }
        };
    }

}
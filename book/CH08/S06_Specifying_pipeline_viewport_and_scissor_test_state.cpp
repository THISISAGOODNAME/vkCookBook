//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  06 Specifying pipeline viewport and scissor test state

#include "S06_Specifying_pipeline_viewport_and_scissor_test_state.h"

namespace VKCookbook {

    void SpecifyPipelineViewportAndScissorTestState( ViewportInfo const                & viewport_infos,
                                                     VkPipelineViewportStateCreateInfo & viewport_state_create_info ){
        uint32_t viewport_count = static_cast<uint32_t>(viewport_infos.Viewports.size());
        uint32_t scissor_count = static_cast<uint32_t>(viewport_infos.Scissors.size());
        viewport_state_create_info = {
                VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,    // VkStructureType                      sType
                nullptr,                                                  // const void                         * pNext
                0,                                                        // VkPipelineViewportStateCreateFlags   flags
                viewport_count,                                           // uint32_t                             viewportCount
                viewport_infos.Viewports.data(),                          // const VkViewport                   * pViewports
                scissor_count,                                            // uint32_t                             scissorCount
                viewport_infos.Scissors.data()                            // const VkRect2D                     * pScissors
        };
    }

}
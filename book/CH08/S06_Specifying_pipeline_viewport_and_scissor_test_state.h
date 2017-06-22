//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  06 Specifying pipeline viewport and scissor test state

#ifndef VKCOOKBOOK_S06_SPECIFYING_PIPELINE_VIEWPORT_AND_SCISSOR_TEST_STATE_H
#define VKCOOKBOOK_S06_SPECIFYING_PIPELINE_VIEWPORT_AND_SCISSOR_TEST_STATE_H

#include "Common.h"

namespace VKCookbook {

    struct ViewportInfo {
        std::vector<VkViewport>   Viewports;
        std::vector<VkRect2D>     Scissors;
    };

    void SpecifyPipelineViewportAndScissorTestState( ViewportInfo const                & viewport_infos,
                                                     VkPipelineViewportStateCreateInfo & viewport_state_create_info );

};


#endif //VKCOOKBOOK_S06_SPECIFYING_PIPELINE_VIEWPORT_AND_SCISSOR_TEST_STATE_H

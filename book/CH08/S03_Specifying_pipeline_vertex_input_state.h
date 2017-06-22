//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  03 Specifying pipeline vertex input state

#ifndef VKCOOKBOOK_S03_SPECIFYING_PIPELINE_VERTEX_INPUT_STATE_H
#define VKCOOKBOOK_S03_SPECIFYING_PIPELINE_VERTEX_INPUT_STATE_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyPipelineVertexInputState( std::vector<VkVertexInputBindingDescription> const   & binding_descriptions,
                                          std::vector<VkVertexInputAttributeDescription> const & attribute_descriptions,
                                          VkPipelineVertexInputStateCreateInfo                 & vertex_input_state_create_info );

} ;


#endif //VKCOOKBOOK_S03_SPECIFYING_PIPELINE_VERTEX_INPUT_STATE_H

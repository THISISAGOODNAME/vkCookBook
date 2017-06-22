//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  19 Binding a pipeline object

#ifndef VKCOOKBOOK_S19_BINDING_A_PIPELINE_OBJECT_H
#define VKCOOKBOOK_S19_BINDING_A_PIPELINE_OBJECT_H

#include "Common.h"

namespace VKCookbook {

    void BindPipelineObject( VkCommandBuffer     command_buffer,
                             VkPipelineBindPoint pipeline_type,
                             VkPipeline          pipeline );

};


#endif //VKCOOKBOOK_S19_BINDING_A_PIPELINE_OBJECT_H

//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  19 Binding a pipeline object

#include "S19_Binding_a_pipeline_object.h"

namespace VKCookbook {

    void BindPipelineObject( VkCommandBuffer     command_buffer,
                             VkPipelineBindPoint pipeline_type,
                             VkPipeline          pipeline ){
        vkCmdBindPipeline( command_buffer, pipeline_type, pipeline );
    }

}
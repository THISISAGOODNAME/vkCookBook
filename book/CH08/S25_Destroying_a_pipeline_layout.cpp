//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  25 Destroying a pipeline layout

#include "S25_Destroying_a_pipeline_layout.h"

namespace VKCookbook {

    void DestroyPipelineLayout( VkDevice           logical_device,
                                VkPipelineLayout & pipeline_layout ){
        if( VK_NULL_HANDLE != pipeline_layout ) {
            vkDestroyPipelineLayout( logical_device, pipeline_layout, nullptr );
            pipeline_layout = VK_NULL_HANDLE;
        }
    }

}
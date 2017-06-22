//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  23 Destroying a pipeline

#include "S23_Destroying_a_pipeline.h"

namespace VKCookbook {

    void DestroyPipeline( VkDevice     logical_device,
                          VkPipeline & pipeline ){
        if( VK_NULL_HANDLE != pipeline ) {
            vkDestroyPipeline( logical_device, pipeline, nullptr );
            pipeline = VK_NULL_HANDLE;
        }
    }

}
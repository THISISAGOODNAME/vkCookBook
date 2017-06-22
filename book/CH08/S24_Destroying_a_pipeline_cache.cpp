//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  24 Destroying a pipeline cache

#include "S24_Destroying_a_pipeline_cache.h"

namespace VKCookbook {

    void DestroyPipelineCache( VkDevice          logical_device,
                               VkPipelineCache & pipeline_cache ){
        if( VK_NULL_HANDLE != pipeline_cache ) {
            vkDestroyPipelineCache( logical_device, pipeline_cache, nullptr );
            pipeline_cache = VK_NULL_HANDLE;
        }
    }

}
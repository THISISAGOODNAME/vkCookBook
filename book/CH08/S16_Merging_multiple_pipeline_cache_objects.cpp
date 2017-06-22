//
// Created by aicdg on 2017/6/22.
//
//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  16 Merging multiple pipeline cache objects

#include "S16_Merging_multiple_pipeline_cache_objects.h"

namespace VKCookbook {

    bool MergeMultiplePipelineCacheObjects( VkDevice                             logical_device,
                                            VkPipelineCache                      target_pipeline_cache,
                                            std::vector<VkPipelineCache> const & source_pipeline_caches ){
        if( source_pipeline_caches.size() > 0 ) {
            VkResult result = vkMergePipelineCaches( logical_device, target_pipeline_cache, static_cast<uint32_t>(source_pipeline_caches.size()), source_pipeline_caches.data() );
            if( VK_SUCCESS != result ) {
                std::cout << "Could not merge pipeline cache objects." << std::endl;
                return false;
            }
            return true;
        }
        return false;
    }

}
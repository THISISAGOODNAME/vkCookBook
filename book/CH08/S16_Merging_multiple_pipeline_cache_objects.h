//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  16 Merging multiple pipeline cache objects

#ifndef VKCOOKBOOK_S16_MERGING_MULTIPLE_PIPELINE_CACHE_OBJECTS_H
#define VKCOOKBOOK_S16_MERGING_MULTIPLE_PIPELINE_CACHE_OBJECTS_H

#include "Common.h"

namespace VKCookbook {

    bool MergeMultiplePipelineCacheObjects( VkDevice                             logical_device,
                                            VkPipelineCache                      target_pipeline_cache,
                                            std::vector<VkPipelineCache> const & source_pipeline_caches );

};


#endif //VKCOOKBOOK_S16_MERGING_MULTIPLE_PIPELINE_CACHE_OBJECTS_H

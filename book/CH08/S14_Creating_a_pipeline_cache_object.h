//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  14 Creating a pipeline cache object

#ifndef VKCOOKBOOK_S14_CREATING_A_PIPELINE_CACHE_OBJECT_H
#define VKCOOKBOOK_S14_CREATING_A_PIPELINE_CACHE_OBJECT_H

#include "Common.h"

namespace VKCookbook {

    bool CreatePipelineCacheObject( VkDevice                           logical_device,
                                    std::vector<unsigned char> const & cache_data,
                                    VkPipelineCache                  & pipeline_cache );

};


#endif //VKCOOKBOOK_S14_CREATING_A_PIPELINE_CACHE_OBJECT_H

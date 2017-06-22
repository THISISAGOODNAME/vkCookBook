//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  24 Destroying a pipeline cache

#ifndef VKCOOKBOOK_S24_DESTROYING_A_PIPELINE_CACHE_H
#define VKCOOKBOOK_S24_DESTROYING_A_PIPELINE_CACHE_H

#include "Common.h"

namespace VKCookbook {

    void DestroyPipelineCache( VkDevice          logical_device,
                               VkPipelineCache & pipeline_cache );

};


#endif //VKCOOKBOOK_S24_DESTROYING_A_PIPELINE_CACHE_H

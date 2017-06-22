//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  15 Retrieving data from a pipeline cache

#ifndef VKCOOKBOOK_S15_RETRIEVING_DATA_FROM_A_PIPELINE_CACHE_H
#define VKCOOKBOOK_S15_RETRIEVING_DATA_FROM_A_PIPELINE_CACHE_H

#include "Common.h"

namespace VKCookbook {

    bool RetrieveDataFromPipelineCache( VkDevice                     logical_device,
                                        VkPipelineCache              pipeline_cache,
                                        std::vector<unsigned char> & pipeline_cache_data );

};


#endif //VKCOOKBOOK_S15_RETRIEVING_DATA_FROM_A_PIPELINE_CACHE_H

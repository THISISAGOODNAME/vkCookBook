//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  22 Creating multiple graphics pipelines on multiple threads

#ifndef VKCOOKBOOK_S22_CREATING_MULTIPLE_GRAPHICS_PIPELINES_ON_MULTIPLE_THREADS_H
#define VKCOOKBOOK_S22_CREATING_MULTIPLE_GRAPHICS_PIPELINES_ON_MULTIPLE_THREADS_H

#include "Common.h"

namespace VKCookbook {

    bool CreateMultipleGraphicsPipelinesOnMultipleThreads( VkDevice                                                       logical_device,
                                                           std::string const                                            & pipeline_cache_filename,
                                                           std::vector<std::vector<VkGraphicsPipelineCreateInfo>> const & graphics_pipelines_create_infos,
                                                           std::vector<std::vector<VkPipeline>>                         & graphics_pipelines );

};


#endif //VKCOOKBOOK_S22_CREATING_MULTIPLE_GRAPHICS_PIPELINES_ON_MULTIPLE_THREADS_H

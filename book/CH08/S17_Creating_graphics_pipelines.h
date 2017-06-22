//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  17 Creating graphics pipelines

#ifndef VKCOOKBOOK_S17_CREATING_GRAPHICS_PIPELINES_H
#define VKCOOKBOOK_S17_CREATING_GRAPHICS_PIPELINES_H

#include "Common.h"

namespace VKCookbook {

    bool CreateGraphicsPipelines( VkDevice                                             logical_device,
                                  std::vector<VkGraphicsPipelineCreateInfo> const    & graphics_pipeline_create_infos,
                                  VkPipelineCache                                      pipeline_cache,
                                  std::vector<VkPipeline>                            & graphics_pipelines );

};


#endif //VKCOOKBOOK_S17_CREATING_GRAPHICS_PIPELINES_H

//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  17 Creating graphics pipelines

#include "S17_Creating_graphics_pipelines.h"

namespace VKCookbook {

    bool CreateGraphicsPipelines( VkDevice                                             logical_device,
                                  std::vector<VkGraphicsPipelineCreateInfo> const    & graphics_pipeline_create_infos,
                                  VkPipelineCache                                      pipeline_cache,
                                  std::vector<VkPipeline>                            & graphics_pipelines ){
        if( graphics_pipeline_create_infos.size() > 0 ) {
            graphics_pipelines.resize( graphics_pipeline_create_infos.size() );
            VkResult result = vkCreateGraphicsPipelines( logical_device, pipeline_cache, static_cast<uint32_t>(graphics_pipeline_create_infos.size()), graphics_pipeline_create_infos.data(), nullptr, graphics_pipelines.data() );
            if( VK_SUCCESS != result ) {
                std::cout << "Could not create a graphics pipeline." << std::endl;
                return false;
            }
            return true;
        }
        return false;
    }

}
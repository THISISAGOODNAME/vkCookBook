//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  06 Providing data to shaders through push constants

#include "S06_Providing_data_to_shaders_through_push_constants.h"

namespace VKCookbook {

    void ProvideDataToShadersThroughPushConstants( VkCommandBuffer      command_buffer,
                                                   VkPipelineLayout     pipeline_layout,
                                                   VkShaderStageFlags   pipeline_stages,
                                                   uint32_t             offset,
                                                   uint32_t             size,
                                                   void               * data ){
        vkCmdPushConstants( command_buffer, pipeline_layout, pipeline_stages, offset, size, data );
    }

}
//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  06 Providing data to shaders through push constants

#ifndef VKCOOKBOOK_S06_PROVIDING_DATA_TO_SHADERS_THROUGH_PUSH_CONSTANTS_H
#define VKCOOKBOOK_S06_PROVIDING_DATA_TO_SHADERS_THROUGH_PUSH_CONSTANTS_H

#include "Common.h"

namespace VKCookbook {

    void ProvideDataToShadersThroughPushConstants( VkCommandBuffer      command_buffer,
                                                   VkPipelineLayout     pipeline_layout,
                                                   VkShaderStageFlags   pipeline_stages,
                                                   uint32_t             offset,
                                                   uint32_t             size,
                                                   void               * data );

};


#endif //VKCOOKBOOK_S06_PROVIDING_DATA_TO_SHADERS_THROUGH_PUSH_CONSTANTS_H

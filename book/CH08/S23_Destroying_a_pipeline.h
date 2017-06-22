//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  23 Destroying a pipeline

#ifndef VKCOOKBOOK_S23_DESTROYING_A_PIPELINE_H
#define VKCOOKBOOK_S23_DESTROYING_A_PIPELINE_H

#include "Common.h"

namespace VKCookbook {

    void DestroyPipeline( VkDevice     logical_device,
                          VkPipeline & pipeline );

};


#endif //VKCOOKBOOK_S23_DESTROYING_A_PIPELINE_H

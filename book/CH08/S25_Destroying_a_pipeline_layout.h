//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  25 Destroying a pipeline layout

#ifndef VKCOOKBOOK_S25_DESTROYING_A_PIPELINE_LAYOUT_H
#define VKCOOKBOOK_S25_DESTROYING_A_PIPELINE_LAYOUT_H

#include "Common.h"

namespace VKCookbook {

    void DestroyPipelineLayout( VkDevice           logical_device,
                                VkPipelineLayout & pipeline_layout );

};


#endif //VKCOOKBOOK_S25_DESTROYING_A_PIPELINE_LAYOUT_H

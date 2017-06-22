//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  26 Destroying a shader module


#ifndef VKCOOKBOOK_S26_DESTROYING_A_SHADER_MODULE_H
#define VKCOOKBOOK_S26_DESTROYING_A_SHADER_MODULE_H

#include "Common.h"

namespace VKCookbook {

    void DestroyShaderModule( VkDevice         logical_device,
                              VkShaderModule & shader_module );

};


#endif //VKCOOKBOOK_S26_DESTROYING_A_SHADER_MODULE_H

//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  01 Creating a shader module

#ifndef VKCOOKBOOK_S01_CREATING_A_SHADER_MODULE_H
#define VKCOOKBOOK_S01_CREATING_A_SHADER_MODULE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateShaderModule( VkDevice                           logical_device,
                             std::vector<unsigned char> const & source_code,
                             VkShaderModule                   & shader_module );

};


#endif //VKCOOKBOOK_S01_CREATING_A_SHADER_MODULE_H

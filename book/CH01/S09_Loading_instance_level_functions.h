//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  09 Loading instance-level functions

#ifndef VKCOOKBOOK_S09_LOADING_INSTANCE_LEVEL_FUNCTIONS_H
#define VKCOOKBOOK_S09_LOADING_INSTANCE_LEVEL_FUNCTIONS_H

#include "Common.h"

namespace VKCookbook {

    bool LoadInstanceLevelFunctions( VkInstance                        instance,
                                     std::vector<char const *> const & enabled_extensions );

};


#endif //VKCOOKBOOK_S09_LOADING_INSTANCE_LEVEL_FUNCTIONS_H

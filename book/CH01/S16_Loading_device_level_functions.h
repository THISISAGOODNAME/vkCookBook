//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  16 Loading device-level functions

#ifndef VKCOOKBOOK_S16_LOADING_DEVICE_LEVEL_FUNCTIONS_H
#define VKCOOKBOOK_S16_LOADING_DEVICE_LEVEL_FUNCTIONS_H

#include "Common.h"

namespace VKCookbook {

    bool LoadDeviceLevelFunctions( VkDevice                          logical_device,
                                   std::vector<char const *> const & enabled_extensions );

};


#endif //VKCOOKBOOK_S16_LOADING_DEVICE_LEVEL_FUNCTIONS_H

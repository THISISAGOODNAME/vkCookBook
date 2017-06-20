//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  10 Resetting fences

#ifndef VKCOOKBOOK_S10_RESETTING_FENCES_H
#define VKCOOKBOOK_S10_RESETTING_FENCES_H

#include "Common.h"

namespace VKCookbook {

    bool ResetFences( VkDevice                     logical_device,
                      std::vector<VkFence> const & fences );

};


#endif //VKCOOKBOOK_S10_RESETTING_FENCES_H

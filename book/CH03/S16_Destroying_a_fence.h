//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  16 Destroying a fence

#ifndef VKCOOKBOOK_S16_DESTROYING_A_FENCE_H
#define VKCOOKBOOK_S16_DESTROYING_A_FENCE_H

#include "Common.h"

namespace VKCookbook {

    void DestroyFence( VkDevice   logical_device,
                       VkFence  & fence );

};


#endif //VKCOOKBOOK_S16_DESTROYING_A_FENCE_H

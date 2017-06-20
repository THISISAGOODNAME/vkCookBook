//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  08 Creating a fence

#ifndef VKCOOKBOOK_S08_CREATING_A_FENCE_H
#define VKCOOKBOOK_S08_CREATING_A_FENCE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateFence( VkDevice   logical_device,
                      bool       signaled,
                      VkFence  & fence );

};


#endif //VKCOOKBOOK_S08_CREATING_A_FENCE_H

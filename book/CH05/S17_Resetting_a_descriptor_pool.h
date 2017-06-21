//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  17 Resetting a descriptor pool

#ifndef VKCOOKBOOK_S17_RESETTING_A_DESCRIPTOR_POOL_H
#define VKCOOKBOOK_S17_RESETTING_A_DESCRIPTOR_POOL_H

#include "Common.h"

namespace VKCookbook {

    bool ResetDescriptorPool( VkDevice          logical_device,
                              VkDescriptorPool  descriptor_pool );

} ;


#endif //VKCOOKBOOK_S17_RESETTING_A_DESCRIPTOR_POOL_H

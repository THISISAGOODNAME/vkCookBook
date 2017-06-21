//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  18 Destroying a descriptor pool

#ifndef VKCOOKBOOK_S18_DESTROYING_A_DESCRIPTOR_POOL_H
#define VKCOOKBOOK_S18_DESTROYING_A_DESCRIPTOR_POOL_H

#include "Common.h"

namespace VKCookbook {

    void DestroyDescriptorPool( VkDevice           logical_device,
                                VkDescriptorPool & descriptor_pool );

} ;


#endif //VKCOOKBOOK_S18_DESTROYING_A_DESCRIPTOR_POOL_H

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  20 Destroying a sampler

#ifndef VKCOOKBOOK_S20_DESTROYING_A_SAMPLER_H
#define VKCOOKBOOK_S20_DESTROYING_A_SAMPLER_H

#include "Common.h"

namespace VKCookbook {

    void DestroySampler( VkDevice    logical_device,
                         VkSampler & sampler );

};


#endif //VKCOOKBOOK_S20_DESTROYING_A_SAMPLER_H

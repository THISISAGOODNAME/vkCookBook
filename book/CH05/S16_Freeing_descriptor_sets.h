//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  16 Freeing descriptor sets

#ifndef VKCOOKBOOK_S16_FREEING_DESCRIPTOR_SETS_H
#define VKCOOKBOOK_S16_FREEING_DESCRIPTOR_SETS_H

#include "Common.h"

namespace VKCookbook {

    bool FreeDescriptorSets( VkDevice                       logical_device,
                             VkDescriptorPool               descriptor_pool,
                             std::vector<VkDescriptorSet> & descriptor_sets );

};


#endif //VKCOOKBOOK_S16_FREEING_DESCRIPTOR_SETS_H

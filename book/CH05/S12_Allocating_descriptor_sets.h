//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  12 Allocating descriptor sets

#ifndef VKCOOKBOOK_S12_ALLOCATING_DESCRIPTOR_SETS_H
#define VKCOOKBOOK_S12_ALLOCATING_DESCRIPTOR_SETS_H

#include "Common.h"

namespace VKCookbook {

    bool AllocateDescriptorSets( VkDevice                                   logical_device,
                                 VkDescriptorPool                           descriptor_pool,
                                 std::vector<VkDescriptorSetLayout> const & descriptor_set_layouts,
                                 std::vector<VkDescriptorSet>             & descriptor_sets );

};


#endif //VKCOOKBOOK_S12_ALLOCATING_DESCRIPTOR_SETS_H

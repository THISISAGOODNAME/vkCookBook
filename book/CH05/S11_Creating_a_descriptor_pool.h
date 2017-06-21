//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  11 Creating a descriptor pool

#ifndef VKCOOKBOOK_S11_CREATING_A_DESCRIPTOR_POOL_H
#define VKCOOKBOOK_S11_CREATING_A_DESCRIPTOR_POOL_H

#include "Common.h"

namespace VKCookbook {

    bool CreateDescriptorPool( VkDevice                                  logical_device,
                               bool                                      free_individual_sets,
                               uint32_t                                  max_sets_count,
                               std::vector<VkDescriptorPoolSize> const & descriptor_types,
                               VkDescriptorPool                        & descriptor_pool );

};


#endif //VKCOOKBOOK_S11_CREATING_A_DESCRIPTOR_POOL_H

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  10 Creating a descriptor set layout

#ifndef VKCOOKBOOK_S10_CREATING_A_DESCRIPTOR_SET_LAYOUT_H
#define VKCOOKBOOK_S10_CREATING_A_DESCRIPTOR_SET_LAYOUT_H

#include "Common.h"

namespace VKCookbook {

    bool CreateDescriptorSetLayout( VkDevice                                          logical_device,
                                    std::vector<VkDescriptorSetLayoutBinding> const & bindings,
                                    VkDescriptorSetLayout                           & descriptor_set_layout );

};


#endif //VKCOOKBOOK_S10_CREATING_A_DESCRIPTOR_SET_LAYOUT_H

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  19 Destroying a descriptor set layout

#ifndef VKCOOKBOOK_S19_DESTROYING_A_DESCRIPTOR_SET_LAYOUT_H
#define VKCOOKBOOK_S19_DESTROYING_A_DESCRIPTOR_SET_LAYOUT_H

#include "Common.h"

namespace VKCookbook {

    void DestroyDescriptorSetLayout( VkDevice                logical_device,
                                     VkDescriptorSetLayout & descriptor_set_layout );

};


#endif //VKCOOKBOOK_S19_DESTROYING_A_DESCRIPTOR_SET_LAYOUT_H

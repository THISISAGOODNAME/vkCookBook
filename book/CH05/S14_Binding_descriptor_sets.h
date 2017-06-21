//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  14 Binding descriptor sets

#ifndef VKCOOKBOOK_S14_BINDING_DESCRIPTOR_SETS_H
#define VKCOOKBOOK_S14_BINDING_DESCRIPTOR_SETS_H

#include "Common.h"

namespace VKCookbook {

    void BindDescriptorSets( VkCommandBuffer                      command_buffer,
                             VkPipelineBindPoint                  pipeline_type,
                             VkPipelineLayout                     pipeline_layout,
                             uint32_t                             index_for_first_set,
                             std::vector<VkDescriptorSet> const & descriptor_sets,
                             std::vector<uint32_t> const        & dynamic_offsets );

};


#endif //VKCOOKBOOK_S14_BINDING_DESCRIPTOR_SETS_H

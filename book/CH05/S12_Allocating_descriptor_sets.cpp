//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  12 Allocating descriptor sets

#include "S12_Allocating_descriptor_sets.h"

namespace VKCookbook {

    bool AllocateDescriptorSets( VkDevice                                   logical_device,
                                 VkDescriptorPool                           descriptor_pool,
                                 std::vector<VkDescriptorSetLayout> const & descriptor_set_layouts,
                                 std::vector<VkDescriptorSet>             & descriptor_sets ) {
        if( descriptor_set_layouts.size() > 0 ) {
            VkDescriptorSetAllocateInfo descriptor_set_allocate_info = {
                    VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,         // VkStructureType                  sType
                    nullptr,                                                // const void                     * pNext
                    descriptor_pool,                                        // VkDescriptorPool                 descriptorPool
                    static_cast<uint32_t>(descriptor_set_layouts.size()),   // uint32_t                         descriptorSetCount
                    descriptor_set_layouts.data()                           // const VkDescriptorSetLayout    * pSetLayouts
            };

            descriptor_sets.resize( descriptor_set_layouts.size() );

            VkResult result = vkAllocateDescriptorSets( logical_device, &descriptor_set_allocate_info, descriptor_sets.data() );
            if( VK_SUCCESS != result ) {
                std::cout << "Could not allocate descriptor sets." << std::endl;
                return false;
            }
            return true;
        }
        return false;
    }

}
//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  16 Freeing descriptor sets

#include "S16_Freeing_descriptor_sets.h"

namespace VKCookbook {

    bool FreeDescriptorSets( VkDevice                       logical_device,
                             VkDescriptorPool               descriptor_pool,
                             std::vector<VkDescriptorSet> & descriptor_sets ) {
        if( descriptor_sets.size() > 0 ) {
            VkResult result = vkFreeDescriptorSets( logical_device, descriptor_pool, static_cast<uint32_t>(descriptor_sets.size()), descriptor_sets.data() );
            descriptor_sets.clear();
            if( VK_SUCCESS != result ) {
                std::cout << "Error occurred during freeing descriptor sets." << std::endl;
                return false;
            }
        }
        return true;
    }

}
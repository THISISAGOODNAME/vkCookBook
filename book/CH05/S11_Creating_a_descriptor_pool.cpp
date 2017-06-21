//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  11 Creating a descriptor pool

#include "S11_Creating_a_descriptor_pool.h"

namespace VKCookbook {

    bool CreateDescriptorPool( VkDevice                                  logical_device,
                               bool                                      free_individual_sets,
                               uint32_t                                  max_sets_count,
                               std::vector<VkDescriptorPoolSize> const & descriptor_types,
                               VkDescriptorPool                        & descriptor_pool ) {
        VkDescriptorPoolCreateInfo descriptor_pool_create_info = {
                VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,                // VkStructureType                sType
                nullptr,                                                      // const void                   * pNext
                free_individual_sets ?                                        // VkDescriptorPoolCreateFlags    flags
                VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT : 0u,
                max_sets_count,                                               // uint32_t                       maxSets
                static_cast<uint32_t>(descriptor_types.size()),               // uint32_t                       poolSizeCount
                descriptor_types.data()                                       // const VkDescriptorPoolSize   * pPoolSizes
        };

        VkResult result = vkCreateDescriptorPool( logical_device, &descriptor_pool_create_info, nullptr, &descriptor_pool );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create a descriptor pool." << std::endl;
            return false;
        }
        return true;
    }

}
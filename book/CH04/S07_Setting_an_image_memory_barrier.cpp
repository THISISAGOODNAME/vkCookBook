//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  07 Setting an image memory barrier

#include "S07_Setting_an_image_memory_barrier.h"

namespace VKCookbook {

    void SetImageMemoryBarrier( VkCommandBuffer              command_buffer,
                                VkPipelineStageFlags         generating_stages,
                                VkPipelineStageFlags         consuming_stages,
                                std::vector<ImageTransition> image_transitions ) {
        std::vector<VkImageMemoryBarrier> image_memory_barriers;

        for( auto & image_transition : image_transitions ) {
            image_memory_barriers.push_back( {
                                                     VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,   // VkStructureType            sType
                                                     nullptr,                                  // const void               * pNext
                                                     image_transition.CurrentAccess,           // VkAccessFlags              srcAccessMask
                                                     image_transition.NewAccess,               // VkAccessFlags              dstAccessMask
                                                     image_transition.CurrentLayout,           // VkImageLayout              oldLayout
                                                     image_transition.NewLayout,               // VkImageLayout              newLayout
                                                     image_transition.CurrentQueueFamily,      // uint32_t                   srcQueueFamilyIndex
                                                     image_transition.NewQueueFamily,          // uint32_t                   dstQueueFamilyIndex
                                                     image_transition.Image,                   // VkImage                    image
                                                     {                                         // VkImageSubresourceRange    subresourceRange
                                                             image_transition.Aspect,                  // VkImageAspectFlags         aspectMask
                                                             0,                                        // uint32_t                   baseMipLevel
                                                             VK_REMAINING_MIP_LEVELS,                  // uint32_t                   levelCount
                                                             0,                                        // uint32_t                   baseArrayLayer
                                                             VK_REMAINING_ARRAY_LAYERS                 // uint32_t                   layerCount
                                                     }
                                             } );
        }

        if( image_memory_barriers.size() > 0 ) {
            vkCmdPipelineBarrier( command_buffer,
                                  generating_stages,
                                  consuming_stages, 0, 0, nullptr, 0, nullptr,
                                  static_cast<uint32_t>(image_memory_barriers.size()),
                                  image_memory_barriers.data() );
        }
    }

}
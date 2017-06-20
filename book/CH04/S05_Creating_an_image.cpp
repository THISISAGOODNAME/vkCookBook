//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  05 Creating an image

#include "S05_Creating_an_image.h"

namespace VKCookbook {

    bool CreateImage( VkDevice                logical_device,
                      VkImageType             type,
                      VkFormat                format,
                      VkExtent3D              size,
                      uint32_t                num_mipmaps,
                      uint32_t                num_layers,
                      VkSampleCountFlagBits   samples,
                      VkImageUsageFlags       usage_scenarios,
                      bool                    cubemap,
                      VkImage               & image ) {
        VkImageCreateInfo image_create_info = {
                VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,                // VkStructureType          sType
                nullptr,                                            // const void             * pNext
                cubemap ? VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT : 0u, // VkImageCreateFlags       flags
                type,                                               // VkImageType              imageType
                format,                                             // VkFormat                 format
                size,                                               // VkExtent3D               extent
                num_mipmaps,                                        // uint32_t                 mipLevels
                cubemap ? 6 * num_layers : num_layers,              // uint32_t                 arrayLayers
                samples,                                            // VkSampleCountFlagBits    samples
                VK_IMAGE_TILING_OPTIMAL,                            // VkImageTiling            tiling
                usage_scenarios,                                    // VkImageUsageFlags        usage
                VK_SHARING_MODE_EXCLUSIVE,                          // VkSharingMode            sharingMode
                0,                                                  // uint32_t                 queueFamilyIndexCount
                nullptr,                                            // const uint32_t         * pQueueFamilyIndices
                VK_IMAGE_LAYOUT_UNDEFINED                           // VkImageLayout            initialLayout
        };

        VkResult result = vkCreateImage( logical_device, &image_create_info, nullptr, &image );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create an image." << std::endl;
            return false;
        }
        return true;
    }

}
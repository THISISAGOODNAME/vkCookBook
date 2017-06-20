//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  08 Creating an image view

#include "S08_Creating_an_image_view.h"

namespace VKCookbook {

    bool CreateImageView( VkDevice             logical_device,
                          VkImage              image,
                          VkImageViewType      view_type,
                          VkFormat             format,
                          VkImageAspectFlags   aspect,
                          VkImageView        & image_view ) {
        VkImageViewCreateInfo image_view_create_info = {
                VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,   // VkStructureType            sType
                nullptr,                                    // const void               * pNext
                0,                                          // VkImageViewCreateFlags     flags
                image,                                      // VkImage                    image
                view_type,                                  // VkImageViewType            viewType
                format,                                     // VkFormat                   format
                {                                           // VkComponentMapping         components
                        VK_COMPONENT_SWIZZLE_IDENTITY,              // VkComponentSwizzle         r
                        VK_COMPONENT_SWIZZLE_IDENTITY,              // VkComponentSwizzle         g
                        VK_COMPONENT_SWIZZLE_IDENTITY,              // VkComponentSwizzle         b
                        VK_COMPONENT_SWIZZLE_IDENTITY               // VkComponentSwizzle         a
                },
                {                                           // VkImageSubresourceRange    subresourceRange
                        aspect,                                     // VkImageAspectFlags         aspectMask
                        0,                                          // uint32_t                   baseMipLevel
                        VK_REMAINING_MIP_LEVELS,                    // uint32_t                   levelCount
                        0,                                          // uint32_t                   baseArrayLayer
                        VK_REMAINING_ARRAY_LAYERS                   // uint32_t                   layerCount
                }
        };

        VkResult result = vkCreateImageView( logical_device, &image_view_create_info, nullptr, &image_view );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create an image view." << std::endl;
            return false;
        }
        return true;
    }

}
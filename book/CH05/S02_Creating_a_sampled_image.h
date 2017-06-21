//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  02 Creating a sampled image

#ifndef VKCOOKBOOK_S02_CREATING_A_SAMPLED_IMAGE_H
#define VKCOOKBOOK_S02_CREATING_A_SAMPLED_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateSampledImage( VkPhysicalDevice    physical_device,
                             VkDevice            logical_device,
                             VkImageType         type,
                             VkFormat            format,
                             VkExtent3D          size,
                             uint32_t            num_mipmaps,
                             uint32_t            num_layers,
                             VkImageUsageFlags   usage,
                             VkImageViewType     view_type,
                             VkImageAspectFlags  aspect,
                             bool                linear_filtering,
                             VkImage           & sampled_image,
                             VkDeviceMemory    & memory_object,
                             VkImageView       & sampled_image_view );

};


#endif //VKCOOKBOOK_S02_CREATING_A_SAMPLED_IMAGE_H

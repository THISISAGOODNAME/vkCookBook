//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  04 Creating a storage image

#ifndef VKCOOKBOOK_S04_CREATING_A_STORAGE_IMAGE_H
#define VKCOOKBOOK_S04_CREATING_A_STORAGE_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateStorageImage( VkPhysicalDevice    physical_device,
                             VkDevice            logical_device,
                             VkImageType         type,
                             VkFormat            format,
                             VkExtent3D          size,
                             uint32_t            num_mipmaps,
                             uint32_t            num_layers,
                             VkImageUsageFlags   usage,
                             VkImageViewType     view_type,
                             VkImageAspectFlags  aspect,
                             bool                atomic_operations,
                             VkImage           & storage_image,
                             VkDeviceMemory    & memory_object,
                             VkImageView       & storage_image_view );

};


#endif //VKCOOKBOOK_S04_CREATING_A_STORAGE_IMAGE_H

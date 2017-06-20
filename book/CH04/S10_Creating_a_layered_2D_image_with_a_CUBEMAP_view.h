//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  10 Creating a layered 2D image with a CUBEMAP view

#ifndef VKCOOKBOOK_S10_CREATING_A_LAYERED_2D_IMAGE_WITH_A_CUBEMAP_VIEW_H
#define VKCOOKBOOK_S10_CREATING_A_LAYERED_2D_IMAGE_WITH_A_CUBEMAP_VIEW_H

#include "Common.h"

namespace VKCookbook {

    bool CreateLayered2DImageWithCubemapView( VkPhysicalDevice    physical_device,
                                              VkDevice            logical_device,
                                              uint32_t            size,
                                              uint32_t            num_mipmaps,
                                              VkImageUsageFlags   usage,
                                              VkImageAspectFlags  aspect,
                                              VkImage           & image,
                                              VkDeviceMemory    & memory_object,
                                              VkImageView       & image_view );

};


#endif //VKCOOKBOOK_S10_CREATING_A_LAYERED_2D_IMAGE_WITH_A_CUBEMAP_VIEW_H

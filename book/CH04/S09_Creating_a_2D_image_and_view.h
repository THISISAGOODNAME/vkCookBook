//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  09 Creating a 2D image and view

#ifndef VKCOOKBOOK_S09_CREATING_A_2D_IMAGE_AND_VIEW_H
#define VKCOOKBOOK_S09_CREATING_A_2D_IMAGE_AND_VIEW_H

#include "Common.h"

namespace VKCookbook {

    bool Create2DImageAndView( VkPhysicalDevice        physical_device,
                               VkDevice                logical_device,
                               VkFormat                format,
                               VkExtent2D              size,
                               uint32_t                num_mipmaps,
                               uint32_t                num_layers,
                               VkSampleCountFlagBits   samples,
                               VkImageUsageFlags       usage,
                               VkImageAspectFlags      aspect,
                               VkImage               & image,
                               VkDeviceMemory        & memory_object,
                               VkImageView           & image_view );

};


#endif //VKCOOKBOOK_S09_CREATING_A_2D_IMAGE_AND_VIEW_H

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  09 Creating an input attachment

#ifndef VKCOOKBOOK_S09_CREATING_AN_INPUT_ATTACHMENT_H
#define VKCOOKBOOK_S09_CREATING_AN_INPUT_ATTACHMENT_H

#include "Common.h"

namespace VKCookbook {

    bool CreateInputAttachment( VkPhysicalDevice     physical_device,
                                VkDevice             logical_device,
                                VkImageType          type,
                                VkFormat             format,
                                VkExtent3D           size,
                                VkImageUsageFlags    usage,
                                VkImageViewType      view_type,
                                VkImageAspectFlags   aspect,
                                VkImage            & input_attachment,
                                VkDeviceMemory     & memory_object,
                                VkImageView        & input_attachment_image_view );

};


#endif //VKCOOKBOOK_S09_CREATING_AN_INPUT_ATTACHMENT_H

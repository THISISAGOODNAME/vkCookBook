//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  05 Creating an image

#ifndef VKCOOKBOOK_S05_CREATING_AN_IMAGE_H
#define VKCOOKBOOK_S05_CREATING_AN_IMAGE_H

#include "Common.h"

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
                      VkImage               & image );

};


#endif //VKCOOKBOOK_S05_CREATING_AN_IMAGE_H

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  18 Destroying an image

#include "S18_Destroying_an_image.h"

namespace VKCookbook {

    void DestroyImage( VkDevice   logical_device,
                       VkImage  & image ) {
        if( VK_NULL_HANDLE != image ) {
            vkDestroyImage( logical_device, image, nullptr );
            image = VK_NULL_HANDLE;
        }
    }

}
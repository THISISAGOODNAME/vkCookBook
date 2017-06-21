//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  17 Destroying an image view

#include "S17_Destroying_an_image_view.h"

namespace VKCookbook {

    void DestroyImageView( VkDevice      logical_device,
                           VkImageView & image_view ) {
        if( VK_NULL_HANDLE != image_view ) {
            vkDestroyImageView( logical_device, image_view, nullptr );
            image_view = VK_NULL_HANDLE;
        }
    }

}
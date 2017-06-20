//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  08 Creating an image view

#ifndef VKCOOKBOOK_S08_CREATING_AN_IMAGE_VIEW_H
#define VKCOOKBOOK_S08_CREATING_AN_IMAGE_VIEW_H

#include "Common.h"

namespace VKCookbook {

    bool CreateImageView( VkDevice             logical_device,
                          VkImage              image,
                          VkImageViewType      view_type,
                          VkFormat             format,
                          VkImageAspectFlags   aspect,
                          VkImageView        & image_view );

};


#endif //VKCOOKBOOK_S08_CREATING_AN_IMAGE_VIEW_H

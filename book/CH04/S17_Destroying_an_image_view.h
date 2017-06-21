//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  17 Destroying an image view

#ifndef VKCOOKBOOK_S17_DESTROYING_AN_IMAGE_VIEW_H
#define VKCOOKBOOK_S17_DESTROYING_AN_IMAGE_VIEW_H

#include "Common.h"

namespace VKCookbook {

    void DestroyImageView( VkDevice      logical_device,
                           VkImageView & image_view );

};


#endif //VKCOOKBOOK_S17_DESTROYING_AN_IMAGE_VIEW_H

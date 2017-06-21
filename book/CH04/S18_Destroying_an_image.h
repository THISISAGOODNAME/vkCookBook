//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  18 Destroying an image

#ifndef VKCOOKBOOK_S18_DESTROYING_AN_IMAGE_H
#define VKCOOKBOOK_S18_DESTROYING_AN_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    void DestroyImage( VkDevice   logical_device,
                       VkImage  & image );

};


#endif //VKCOOKBOOK_S18_DESTROYING_AN_IMAGE_H

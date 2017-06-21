//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  19 Destroying a buffer view

#ifndef VKCOOKBOOK_S19_DESTROYING_A_BUFFER_VIEW_H
#define VKCOOKBOOK_S19_DESTROYING_A_BUFFER_VIEW_H

#include "Common.h"

namespace VKCookbook {

    void DestroyBufferView( VkDevice       logical_device,
                            VkBufferView & buffer_view );

};


#endif //VKCOOKBOOK_S19_DESTROYING_A_BUFFER_VIEW_H

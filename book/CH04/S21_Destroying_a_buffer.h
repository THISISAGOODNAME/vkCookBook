//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  21 Destroying a buffer

#ifndef VKCOOKBOOK_S21_DESTROYING_A_BUFFER_H
#define VKCOOKBOOK_S21_DESTROYING_A_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    void DestroyBuffer( VkDevice   logical_device,
                        VkBuffer & buffer );

};


#endif //VKCOOKBOOK_S21_DESTROYING_A_BUFFER_H

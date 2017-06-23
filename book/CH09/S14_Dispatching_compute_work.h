//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  14 Dispatching compute work

#ifndef VKCOOKBOOK_S14_DISPATCHING_COMPUTE_WORK_H
#define VKCOOKBOOK_S14_DISPATCHING_COMPUTE_WORK_H

#include "Common.h"

namespace VKCookbook {

    void DispatchComputeWork( VkCommandBuffer command_buffer,
                              uint32_t        x_size,
                              uint32_t        y_size,
                              uint32_t        z_size );

};


#endif //VKCOOKBOOK_S14_DISPATCHING_COMPUTE_WORK_H

//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  14 Dispatching compute work

#include "S14_Dispatching_compute_work.h"

namespace VKCookbook {

    void DispatchComputeWork( VkCommandBuffer command_buffer,
                              uint32_t        x_size,
                              uint32_t        y_size,
                              uint32_t        z_size ){
        vkCmdDispatch( command_buffer, x_size, y_size, z_size );
    }

}
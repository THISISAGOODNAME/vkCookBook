//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  09 Setting line width state dynamically

#include "S09_Setting_line_width_state_dynamically.h"

namespace VKCookbook {

    void SetLineWidthStateDynamically( VkCommandBuffer command_buffer,
                                       float           line_width ){
        vkCmdSetLineWidth( command_buffer, line_width );
    }

}
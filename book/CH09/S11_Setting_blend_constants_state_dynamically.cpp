//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  11 Setting blend constants state dynamically

#include "S11_Setting_blend_constants_state_dynamically.h"

namespace VKCookbook {

    void SetBlendConstantsStateDynamically( VkCommandBuffer              command_buffer,
                                            std::array<float, 4> const & blend_constants ){
        vkCmdSetBlendConstants( command_buffer, blend_constants.data() );
    }

}
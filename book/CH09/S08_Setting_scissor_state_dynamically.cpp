//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  08 Setting scissor state dynamically

#include "S08_Setting_scissor_state_dynamically.h"

namespace VKCookbook {

    void SetScissorStateDynamically( VkCommandBuffer               command_buffer,
                                     uint32_t                      first_scissor,
                                     std::vector<VkRect2D> const & scissors ){
        vkCmdSetScissor( command_buffer, first_scissor, static_cast<uint32_t>(scissors.size()), scissors.data() );
    }

}
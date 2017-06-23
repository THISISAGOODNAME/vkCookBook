//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  07 Setting viewport state dynamically

#include "S07_Setting_viewport_state_dynamically.h"

namespace VKCookbook {

    void SetViewportStateDynamically( VkCommandBuffer                 command_buffer,
                                      uint32_t                        first_viewport,
                                      std::vector<VkViewport> const & viewports ){
        vkCmdSetViewport( command_buffer, first_viewport, static_cast<uint32_t>(viewports.size()), viewports.data() );
    }

}
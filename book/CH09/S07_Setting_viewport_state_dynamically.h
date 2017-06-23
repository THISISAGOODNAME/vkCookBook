//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  07 Setting viewport state dynamically

#ifndef VKCOOKBOOK_S07_SETTING_VIEWPORT_STATE_DYNAMICALLY_H
#define VKCOOKBOOK_S07_SETTING_VIEWPORT_STATE_DYNAMICALLY_H

#include "Common.h"

namespace VKCookbook {

    void SetViewportStateDynamically( VkCommandBuffer                 command_buffer,
                                      uint32_t                        first_viewport,
                                      std::vector<VkViewport> const & viewports );

};


#endif //VKCOOKBOOK_S07_SETTING_VIEWPORT_STATE_DYNAMICALLY_H

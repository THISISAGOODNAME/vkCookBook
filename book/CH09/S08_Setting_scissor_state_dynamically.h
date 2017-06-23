//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  08 Setting scissor state dynamically

#ifndef VKCOOKBOOK_S08_SETTING_SCISSOR_STATE_DYNAMICALLY_H
#define VKCOOKBOOK_S08_SETTING_SCISSOR_STATE_DYNAMICALLY_H

#include "Common.h"

namespace VKCookbook {

    void SetScissorStateDynamically( VkCommandBuffer               command_buffer,
                                     uint32_t                      first_scissor,
                                     std::vector<VkRect2D> const & scissors );

};


#endif //VKCOOKBOOK_S08_SETTING_SCISSOR_STATE_DYNAMICALLY_H

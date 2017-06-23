//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  11 Setting blend constants state dynamically

#ifndef VKCOOKBOOK_S11_SETTING_BLEND_CONSTANTS_STATE_DYNAMICALLY_H
#define VKCOOKBOOK_S11_SETTING_BLEND_CONSTANTS_STATE_DYNAMICALLY_H

#include "Common.h"

namespace VKCookbook {

    void SetBlendConstantsStateDynamically( VkCommandBuffer              command_buffer,
                                            std::array<float, 4> const & blend_constants );

};


#endif //VKCOOKBOOK_S11_SETTING_BLEND_CONSTANTS_STATE_DYNAMICALLY_H

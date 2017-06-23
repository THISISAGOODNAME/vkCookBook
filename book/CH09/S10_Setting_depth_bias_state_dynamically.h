//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  10 Setting depth bias state dynamically

#ifndef VKCOOKBOOK_S10_SETTING_DEPTH_BIAS_STATE_DYNAMICALLY_H
#define VKCOOKBOOK_S10_SETTING_DEPTH_BIAS_STATE_DYNAMICALLY_H

#include "Common.h"

namespace VKCookbook {

    void SetDepthBiasStateDynamically( VkCommandBuffer command_buffer,
                                       float           constant_factor,
                                       float           clamp_value,
                                       float           slope_factor );

};


#endif //VKCOOKBOOK_S10_SETTING_DEPTH_BIAS_STATE_DYNAMICALLY_H

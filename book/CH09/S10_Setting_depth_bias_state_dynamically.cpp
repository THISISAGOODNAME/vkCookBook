//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  10 Setting depth bias state dynamically

#include "S10_Setting_depth_bias_state_dynamically.h"

namespace VKCookbook {

    void SetDepthBiasStateDynamically( VkCommandBuffer command_buffer,
                                       float           constant_factor,
                                       float           clamp_value,
                                       float           slope_factor ){
        vkCmdSetDepthBias( command_buffer, constant_factor, clamp_value, slope_factor );
    }

}
//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  05 Resetting a command buffer

#ifndef VKCOOKBOOK_S05_RESETTING_A_COMMAND_BUFFER_H
#define VKCOOKBOOK_S05_RESETTING_A_COMMAND_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    bool ResetCommandBuffer( VkCommandBuffer command_buffer,
                             bool            release_resources );

};


#endif //VKCOOKBOOK_S05_RESETTING_A_COMMAND_BUFFER_H

//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  03 Setting a buffer memory barrier

#ifndef VKCOOKBOOK_S03_SETTING_A_BUFFER_MEMORY_BARRIER_H
#define VKCOOKBOOK_S03_SETTING_A_BUFFER_MEMORY_BARRIER_H

#include "Common.h"

namespace VKCookbook {

    struct BufferTransition {
        VkBuffer        Buffer;
        VkAccessFlags   CurrentAccess;
        VkAccessFlags   NewAccess;
        uint32_t        CurrentQueueFamily;
        uint32_t        NewQueueFamily;
    };

    void SetBufferMemoryBarrier( VkCommandBuffer               command_buffer,
                                 VkPipelineStageFlags          generating_stages,
                                 VkPipelineStageFlags          consuming_stages,
                                 std::vector<BufferTransition> buffer_transitions );

};


#endif //VKCOOKBOOK_S03_SETTING_A_BUFFER_MEMORY_BARRIER_H

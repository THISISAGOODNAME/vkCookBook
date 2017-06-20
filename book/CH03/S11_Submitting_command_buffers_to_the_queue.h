//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  11 Submitting command buffers to the queue

#ifndef VKCOOKBOOK_S11_SUBMITTING_COMMAND_BUFFERS_TO_THE_QUEUE_H
#define VKCOOKBOOK_S11_SUBMITTING_COMMAND_BUFFERS_TO_THE_QUEUE_H

#include "Common.h"

namespace VKCookbook {

    struct WaitSemaphoreInfo {
        VkSemaphore           Semaphore;
        VkPipelineStageFlags  WaitingStage;
    };

    bool SubmitCommandBuffersToQueue( VkQueue                         queue,
                                      std::vector<WaitSemaphoreInfo>  wait_semaphore_infos,
                                      std::vector<VkCommandBuffer>    command_buffers,
                                      std::vector<VkSemaphore>        signal_semaphores,
                                      VkFence                         fence );

};


#endif //VKCOOKBOOK_S11_SUBMITTING_COMMAND_BUFFERS_TO_THE_QUEUE_H

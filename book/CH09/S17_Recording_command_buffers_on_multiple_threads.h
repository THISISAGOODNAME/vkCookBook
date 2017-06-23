//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  17 Recording command buffers on multiple threads

#ifndef VKCOOKBOOK_S17_RECORDING_COMMAND_BUFFERS_ON_MULTIPLE_THREADS_H
#define VKCOOKBOOK_S17_RECORDING_COMMAND_BUFFERS_ON_MULTIPLE_THREADS_H

#include "../CH03/S11_Submitting_command_buffers_to_the_queue.h"

namespace VKCookbook {

    struct CommandBufferRecordingThreadParameters {
        VkCommandBuffer                         CommandBuffer;
        std::function<bool( VkCommandBuffer )>  RecordingFunction;
    };

    bool RecordCommandBuffersOnMultipleThreads( std::vector<CommandBufferRecordingThreadParameters> const & threads_parameters,
                                                VkQueue                                                     queue,
                                                std::vector<WaitSemaphoreInfo>                              wait_semaphore_infos,
                                                std::vector<VkSemaphore>                                    signal_semaphores,
                                                VkFence                                                     fence );

};


#endif //VKCOOKBOOK_S17_RECORDING_COMMAND_BUFFERS_ON_MULTIPLE_THREADS_H

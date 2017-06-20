//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  12 Synchronizing two command buffers

#ifndef VKCOOKBOOK_S12_SYNCHRONIZING_TWO_COMMAND_BUFFERS_H
#define VKCOOKBOOK_S12_SYNCHRONIZING_TWO_COMMAND_BUFFERS_H

#include "S11_Submitting_command_buffers_to_the_queue.h"

namespace VKCookbook {

    bool SynchronizeTwoCommandBuffers( VkQueue                         first_queue,
                                       std::vector<WaitSemaphoreInfo>  first_wait_semaphore_infos,
                                       std::vector<VkCommandBuffer>    first_command_buffers,
                                       std::vector<WaitSemaphoreInfo>  synchronizing_semaphores,
                                       VkQueue                         second_queue,
                                       std::vector<VkCommandBuffer>    second_command_buffers,
                                       std::vector<VkSemaphore>        second_signal_semaphores,
                                       VkFence                         second_fence );

};


#endif //VKCOOKBOOK_S12_SYNCHRONIZING_TWO_COMMAND_BUFFERS_H

//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  12 Synchronizing two command buffers

#include "S07_Creating_a_semaphore.h"
#include "S12_Synchronizing_two_command_buffers.h"

namespace VKCookbook {

    bool SynchronizeTwoCommandBuffers( VkQueue                         first_queue,
                                       std::vector<WaitSemaphoreInfo>  first_wait_semaphore_infos,
                                       std::vector<VkCommandBuffer>    first_command_buffers,
                                       std::vector<WaitSemaphoreInfo>  synchronizing_semaphores,
                                       VkQueue                         second_queue,
                                       std::vector<VkCommandBuffer>    second_command_buffers,
                                       std::vector<VkSemaphore>        second_signal_semaphores,
                                       VkFence                         second_fence ) {
        std::vector<VkSemaphore> first_signal_semaphores;
        for( auto & semaphore_info : synchronizing_semaphores ) {
            first_signal_semaphores.emplace_back( semaphore_info.Semaphore );
        }
        if( !SubmitCommandBuffersToQueue( first_queue, first_wait_semaphore_infos, first_command_buffers, first_signal_semaphores, VK_NULL_HANDLE ) ) {
            return false;
        }

        if( !SubmitCommandBuffersToQueue( second_queue, synchronizing_semaphores, second_command_buffers, second_signal_semaphores, second_fence ) ) {
            return false;
        }
        return true;
    }

}
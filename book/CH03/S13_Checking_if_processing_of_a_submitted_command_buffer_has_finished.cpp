//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  13 Checking if processing of a submitted command buffer has finished

#include "S09_Waiting_for_fences.h"
#include "S13_Checking_if_processing_of_a_submitted_command_buffer_has_finished.h"

namespace VKCookbook {

    bool CheckIfProcessingOfSubmittedCommandBufferHasFinished( VkDevice                         logical_device,
                                                               VkQueue                          queue,
                                                               std::vector<WaitSemaphoreInfo>   wait_semaphore_infos,
                                                               std::vector<VkCommandBuffer>     command_buffers,
                                                               std::vector<VkSemaphore>         signal_semaphores,
                                                               VkFence                          fence,
                                                               uint64_t                         timeout,
                                                               VkResult                       & wait_status ) {
        if ( !SubmitCommandBuffersToQueue( queue, wait_semaphore_infos, command_buffers, signal_semaphores, fence ) ) {
            return false;
        }

        return WaitForFences( logical_device, { fence }, VK_FALSE, timeout );
    }

}
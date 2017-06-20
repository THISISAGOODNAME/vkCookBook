//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  13 Checking if processing of a submitted command buffer has finished

#ifndef VKCOOKBOOK_S13_CHECKING_IF_PROCESSING_OF_A_SUBMITTED_COMMAND_BUFFER_HAS_FINISHED_H
#define VKCOOKBOOK_S13_CHECKING_IF_PROCESSING_OF_A_SUBMITTED_COMMAND_BUFFER_HAS_FINISHED_H

#include "S11_Submitting_command_buffers_to_the_queue.h"

namespace VKCookbook {

    bool CheckIfProcessingOfSubmittedCommandBufferHasFinished( VkDevice                         logical_device,
                                                               VkQueue                          queue,
                                                               std::vector<WaitSemaphoreInfo>   wait_semaphore_infos,
                                                               std::vector<VkCommandBuffer>     command_buffers,
                                                               std::vector<VkSemaphore>         signal_semaphores,
                                                               VkFence                          fence,
                                                               uint64_t                         timeout,
                                                               VkResult                       & wait_status );

};


#endif //VKCOOKBOOK_S13_CHECKING_IF_PROCESSING_OF_A_SUBMITTED_COMMAND_BUFFER_HAS_FINISHED_H

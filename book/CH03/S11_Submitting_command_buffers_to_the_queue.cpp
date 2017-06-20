//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  11 Submitting command buffers to the queue

#include "S11_Submitting_command_buffers_to_the_queue.h"

namespace VKCookbook {
    bool SubmitCommandBuffersToQueue( VkQueue                         queue,
                                      std::vector<WaitSemaphoreInfo>  wait_semaphore_infos,
                                      std::vector<VkCommandBuffer>    command_buffers,
                                      std::vector<VkSemaphore>        signal_semaphores,
                                      VkFence                         fence ) {
        std::vector<VkSemaphore>          wait_semaphore_handles;
        std::vector<VkPipelineStageFlags> wait_semaphore_stages;

        for( auto & wait_semaphore_info : wait_semaphore_infos ) {
            wait_semaphore_handles.emplace_back( wait_semaphore_info.Semaphore );
            wait_semaphore_stages.emplace_back( wait_semaphore_info.WaitingStage );
        }

        VkSubmitInfo submit_info = {
                VK_STRUCTURE_TYPE_SUBMIT_INFO,                        // VkStructureType                sType
                nullptr,                                              // const void                   * pNext
                static_cast<uint32_t>(wait_semaphore_infos.size()),   // uint32_t                       waitSemaphoreCount
                wait_semaphore_handles.data(),                        // const VkSemaphore            * pWaitSemaphores
                wait_semaphore_stages.data(),                         // const VkPipelineStageFlags   * pWaitDstStageMask
                static_cast<uint32_t>(command_buffers.size()),        // uint32_t                       commandBufferCount
                command_buffers.data(),                               // const VkCommandBuffer        * pCommandBuffers
                static_cast<uint32_t>(signal_semaphores.size()),      // uint32_t                       signalSemaphoreCount
                signal_semaphores.data()                              // const VkSemaphore            * pSignalSemaphores
        };

        VkResult result = vkQueueSubmit( queue, 1, &submit_info, fence );
        if( VK_SUCCESS != result ) {
            std::cout << "Error occurred during command buffer submission." << std::endl;
            return false;
        }
        return true;
    }

}

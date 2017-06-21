//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  15 Using staging buffer to update buffer with a device-local memory bound

#ifndef VKCOOKBOOK_S15_USING_STAGING_BUFFER_TO_UPDATE_A_BUFFER_WITH_A_DEVICE_LOCAL_MEMORY_BOUND_H
#define VKCOOKBOOK_S15_USING_STAGING_BUFFER_TO_UPDATE_A_BUFFER_WITH_A_DEVICE_LOCAL_MEMORY_BOUND_H

#include "Common.h"

namespace VKCookbook {

    bool UseStagingBufferToUpdateBufferWithDeviceLocalMemoryBound( VkPhysicalDevice           physical_device,
                                                                   VkDevice                   logical_device,
                                                                   VkDeviceSize               data_size,
                                                                   void                     * data,
                                                                   VkBuffer                   destination_buffer,
                                                                   VkDeviceSize               destination_offset,
                                                                   VkAccessFlags              destination_buffer_current_access,
                                                                   VkAccessFlags              destination_buffer_new_access,
                                                                   VkPipelineStageFlags       destination_buffer_generating_stages,
                                                                   VkPipelineStageFlags       destination_buffer_consuming_stages,
                                                                   VkQueue                    queue,
                                                                   VkCommandBuffer            command_buffer,
                                                                   std::vector<VkSemaphore>   signal_semaphores );

};


#endif //VKCOOKBOOK_S15_USING_STAGING_BUFFER_TO_UPDATE_A_BUFFER_WITH_A_DEVICE_LOCAL_MEMORY_BOUND_H

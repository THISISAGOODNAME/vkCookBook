//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  16 Using staging buffer to update an image with a device-local memory bound

#ifndef VKCOOKBOOK_S16_USING_STAGING_BUFFER_TO_UPDATE_AN_IMAGE_WITH_A_DEVICE_LOCAL_MEMORY_BOUND_H
#define VKCOOKBOOK_S16_USING_STAGING_BUFFER_TO_UPDATE_AN_IMAGE_WITH_A_DEVICE_LOCAL_MEMORY_BOUND_H

#include "Common.h"

namespace VKCookbook {

    bool UseStagingBufferToUpdateImageWithDeviceLocalMemoryBound( VkPhysicalDevice           physical_device,
                                                                  VkDevice                   logical_device,
                                                                  VkDeviceSize               data_size,
                                                                  void                     * data,
                                                                  VkImage                    destination_image,
                                                                  VkImageSubresourceLayers   destination_image_subresource,
                                                                  VkOffset3D                 destination_image_offset,
                                                                  VkExtent3D                 destination_image_size,
                                                                  VkImageLayout              destination_image_current_layout,
                                                                  VkImageLayout              destination_image_new_layout,
                                                                  VkAccessFlags              destination_image_current_access,
                                                                  VkAccessFlags              destination_image_new_access,
                                                                  VkImageAspectFlags         destination_image_aspect,
                                                                  VkPipelineStageFlags       destination_image_generating_stages,
                                                                  VkPipelineStageFlags       destination_image_consuming_stages,
                                                                  VkQueue                    queue,
                                                                  VkCommandBuffer            command_buffer,
                                                                  std::vector<VkSemaphore>   signal_semaphores );

};


#endif //VKCOOKBOOK_S16_USING_STAGING_BUFFER_TO_UPDATE_AN_IMAGE_WITH_A_DEVICE_LOCAL_MEMORY_BOUND_H

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  15 Using staging buffer to update buffer with a device-local memory bound

#include "../CH03/S03_Beginning_a_command_buffer_recording_operation.h"
#include "../CH03/S04_Ending_a_command_buffer_recording_operation.h"
#include "../CH03/S08_Creating_a_fence.h"
#include "../CH03/S09_Waiting_for_fences.h"
#include "../CH03/S11_Submitting_command_buffers_to_the_queue.h"
#include "S01_Creating_a_buffer.h"
#include "S02_Allocating_and_binding_memory_object_to_a_buffer.h"
#include "S03_Setting_a_buffer_memory_barrier.h"
#include "S11_Mapping_updating_and_unmapping_host_visible_memory.h"
#include "S12_Copying_data_between_buffers.h"
#include "S15_Using_staging_buffer_to_update_a_buffer_with_a_device_local_memory_bound.h"

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
                                                                   std::vector<VkSemaphore>   signal_semaphores ){
        VkDestroyer<VkBuffer> staging_buffer( logical_device );
        if( !CreateBuffer( logical_device, data_size, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, *staging_buffer ) ) {
            return false;
        }

        VkDestroyer<VkDeviceMemory> memory_object( logical_device );
        if( !AllocateAndBindMemoryObjectToBuffer( physical_device, logical_device, *staging_buffer, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, *memory_object ) ) {
            return false;
        }

        if( !MapUpdateAndUnmapHostVisibleMemory( logical_device, *memory_object, 0, data_size, data, true, nullptr ) ) {
            return false;
        }

        if( !BeginCommandBufferRecordingOperation( command_buffer, VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT, nullptr ) ) {
            return false;
        }

        SetBufferMemoryBarrier( command_buffer, destination_buffer_generating_stages, VK_PIPELINE_STAGE_TRANSFER_BIT, { { destination_buffer, destination_buffer_current_access, VK_ACCESS_TRANSFER_WRITE_BIT, VK_QUEUE_FAMILY_IGNORED, VK_QUEUE_FAMILY_IGNORED } } );

        CopyDataBetweenBuffers( command_buffer, *staging_buffer, destination_buffer, { { 0, destination_offset, data_size } } );

        SetBufferMemoryBarrier( command_buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, destination_buffer_consuming_stages, { { destination_buffer, VK_ACCESS_TRANSFER_WRITE_BIT, destination_buffer_new_access, VK_QUEUE_FAMILY_IGNORED, VK_QUEUE_FAMILY_IGNORED } } );

        if( !EndCommandBufferRecordingOperation( command_buffer ) ) {
            return false;
        }

        VkDestroyer<VkFence> fence( logical_device );
        if( !CreateFence( logical_device, false, *fence ) ) {
            return false;
        }

        if( !SubmitCommandBuffersToQueue( queue, {}, { command_buffer }, signal_semaphores, *fence ) ) {
            return false;
        }

        if( !WaitForFences( logical_device, { *fence }, VK_FALSE, 500000000 ) ) {
            return false;
        }

        return true;
    }

}
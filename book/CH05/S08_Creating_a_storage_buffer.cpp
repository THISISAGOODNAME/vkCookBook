//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  08 Creating a storage buffer

#include "../CH04/S01_Creating_a_buffer.h"
#include "../CH04/S02_Allocating_and_binding_memory_object_to_a_buffer.h"
#include "S08_Creating_a_storage_buffer.h"

namespace VKCookbook {

    bool CreateStorageBuffer( VkPhysicalDevice     physical_device,
                              VkDevice             logical_device,
                              VkDeviceSize         size,
                              VkBufferUsageFlags   usage,
                              VkBuffer           & storage_buffer,
                              VkDeviceMemory     & memory_object ) {
        if( !CreateBuffer( logical_device, size, usage | VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, storage_buffer ) ) {
            return false;
        }

        if( !AllocateAndBindMemoryObjectToBuffer( physical_device, logical_device, storage_buffer, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
            return false;
        }
        return true;
    }

}
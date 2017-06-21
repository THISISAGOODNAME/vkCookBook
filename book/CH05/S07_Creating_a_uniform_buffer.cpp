//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  07 Creating a uniform buffer

#include "../CH04/S01_Creating_a_buffer.h"
#include "../CH04/S02_Allocating_and_binding_memory_object_to_a_buffer.h"
#include "S07_Creating_a_uniform_buffer.h"

namespace VKCookbook {

    bool CreateUniformBuffer( VkPhysicalDevice     physical_device,
                              VkDevice             logical_device,
                              VkDeviceSize         size,
                              VkBufferUsageFlags   usage,
                              VkBuffer           & uniform_buffer,
                              VkDeviceMemory     & memory_object ) {
        if( !CreateBuffer( logical_device, size, usage | VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, uniform_buffer ) ) {
            return false;
        }

        if( !AllocateAndBindMemoryObjectToBuffer( physical_device, logical_device, uniform_buffer, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
            return false;
        }
        return true;
    }

}
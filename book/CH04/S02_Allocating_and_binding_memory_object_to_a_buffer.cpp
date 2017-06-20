//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  02 Allocating and binding memory object to a buffer

#include "S02_Allocating_and_binding_memory_object_to_a_buffer.h"

namespace VKCookbook {

    bool AllocateAndBindMemoryObjectToBuffer( VkPhysicalDevice           physical_device,
                                              VkDevice                   logical_device,
                                              VkBuffer                   buffer,
                                              VkMemoryPropertyFlagBits   memory_properties,
                                              VkDeviceMemory           & memory_object ) {
        VkPhysicalDeviceMemoryProperties physical_device_memory_properties;
        vkGetPhysicalDeviceMemoryProperties( physical_device, &physical_device_memory_properties );

        VkMemoryRequirements memory_requirements;
        vkGetBufferMemoryRequirements( logical_device, buffer, &memory_requirements );

        memory_object = VK_NULL_HANDLE;
        for( uint32_t type = 0; type < physical_device_memory_properties.memoryTypeCount; ++type ) {
            if( (memory_requirements.memoryTypeBits & (1 << type)) &&
                ((physical_device_memory_properties.memoryTypes[type].propertyFlags & memory_properties) == memory_properties) ) {

                VkMemoryAllocateInfo buffer_memory_allocate_info = {
                        VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,   // VkStructureType    sType
                        nullptr,                                  // const void       * pNext
                        memory_requirements.size,                 // VkDeviceSize       allocationSize
                        type                                      // uint32_t           memoryTypeIndex
                };

                VkResult result = vkAllocateMemory( logical_device, &buffer_memory_allocate_info, nullptr, &memory_object );
                if( VK_SUCCESS == result ) {
                    break;
                }
            }
        }

        if( VK_NULL_HANDLE == memory_object ) {
            std::cout << "Could not allocate memory for a buffer." << std::endl;
            return false;
        }

        VkResult result = vkBindBufferMemory( logical_device, buffer, memory_object, 0 );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not bind memory object to a buffer." << std::endl;
            return false;
        }
        return true;
    }

}
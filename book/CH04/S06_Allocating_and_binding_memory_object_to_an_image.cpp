//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  06 Allocating and binding memory object to an image

#include "S06_Allocating_and_binding_memory_object_to_an_image.h"

namespace VKCookbook {

    bool AllocateAndBindMemoryObjectToImage( VkPhysicalDevice           physical_device,
                                             VkDevice                   logical_device,
                                             VkImage                    image,
                                             VkMemoryPropertyFlagBits   memory_properties,
                                             VkDeviceMemory           & memory_object ) {
        VkPhysicalDeviceMemoryProperties physical_device_memory_properties;
        vkGetPhysicalDeviceMemoryProperties( physical_device, &physical_device_memory_properties );

        VkMemoryRequirements memory_requirements;
        vkGetImageMemoryRequirements( logical_device, image, &memory_requirements );

        memory_object = VK_NULL_HANDLE;
        for( uint32_t type = 0; type < physical_device_memory_properties.memoryTypeCount; ++type ) {
            if( (memory_requirements.memoryTypeBits & (1 << type)) &&
                ((physical_device_memory_properties.memoryTypes[type].propertyFlags & memory_properties) == memory_properties) ) {

                VkMemoryAllocateInfo image_memory_allocate_info = {
                        VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,   // VkStructureType    sType
                        nullptr,                                  // const void       * pNext
                        memory_requirements.size,                 // VkDeviceSize       allocationSize
                        type                                      // uint32_t           memoryTypeIndex
                };

                VkResult result = vkAllocateMemory( logical_device, &image_memory_allocate_info, nullptr, &memory_object );
                if( VK_SUCCESS == result ) {
                    break;
                }
            }
        }

        if( VK_NULL_HANDLE == memory_object ) {
            std::cout << "Could not allocate memory for an image." << std::endl;
            return false;
        }

        VkResult result = vkBindImageMemory( logical_device, image, memory_object, 0 );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not bind memory object to an image." << std::endl;
            return false;
        }
        return true;
    }

}
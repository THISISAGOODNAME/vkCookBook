//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  06 Creating a storage texel buffer

#include "../Ch04/S01_Creating_a_buffer.h"
#include "../Ch04/S02_Allocating_and_binding_memory_object_to_a_buffer.h"
#include "../CH04/S04_Creating_a_buffer_view.h"
#include "S06_Creating_a_storage_texel_buffer.h"

namespace VKCookbook {

    bool CreateStorageTexelBuffer( VkPhysicalDevice     physical_device,
                                   VkDevice             logical_device,
                                   VkFormat             format,
                                   VkDeviceSize         size,
                                   VkBufferUsageFlags   usage,
                                   bool                 atomic_operations,
                                   VkBuffer           & storage_texel_buffer,
                                   VkDeviceMemory     & memory_object,
                                   VkBufferView       & storage_texel_buffer_view ) {
        VkFormatProperties format_properties;
        vkGetPhysicalDeviceFormatProperties( physical_device, format, &format_properties );
        if( !(format_properties.bufferFeatures & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT) ) {
            std::cout << "Provided format is not supported for a uniform texel buffer." << std::endl;
            return false;
        }

        if( atomic_operations &&
            !(format_properties.bufferFeatures & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT) ) {
            std::cout << "Provided format is not supported for atomic operations on storage texel buffers." << std::endl;
            return false;
        }

        if( !CreateBuffer( logical_device, size, usage | VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT, storage_texel_buffer ) ) {
            return false;
        }

        if( !AllocateAndBindMemoryObjectToBuffer( physical_device, logical_device, storage_texel_buffer, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
            return false;
        }

        if( !CreateBufferView( logical_device, storage_texel_buffer, format, 0, VK_WHOLE_SIZE, storage_texel_buffer_view ) ) {
            return false;
        }
        return true;
    }

}
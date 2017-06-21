//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  05 Creating a uniform texel buffer

#include "../CH04/S01_Creating_a_buffer.h"
#include "../CH04/S02_Allocating_and_binding_memory_object_to_a_buffer.h"
#include "../CH04/S04_Creating_a_buffer_view.h"
#include "S05_Creating_a_uniform_texel_buffer.h"

namespace VKCookbook {

    bool CreateUniformTexelBuffer( VkPhysicalDevice     physical_device,
                                   VkDevice             logical_device,
                                   VkFormat             format,
                                   VkDeviceSize         size,
                                   VkImageUsageFlags    usage,
                                   VkBuffer           & uniform_texel_buffer,
                                   VkDeviceMemory     & memory_object,
                                   VkBufferView       & uniform_texel_buffer_view ) {
        VkFormatProperties format_properties;
        vkGetPhysicalDeviceFormatProperties( physical_device, format, &format_properties );
        if( !(format_properties.bufferFeatures & VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT) ) {
            std::cout << "Provided format is not supported for a uniform texel buffer." << std::endl;
            return false;
        }

        if( !CreateBuffer( logical_device, size, usage | VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT, uniform_texel_buffer ) ) {
            return false;
        }

        if( !AllocateAndBindMemoryObjectToBuffer( physical_device, logical_device, uniform_texel_buffer, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
            return false;
        }

        if( !CreateBufferView( logical_device, uniform_texel_buffer, format, 0, VK_WHOLE_SIZE, uniform_texel_buffer_view ) ) {
            return false;
        }
        return true;
    }

}
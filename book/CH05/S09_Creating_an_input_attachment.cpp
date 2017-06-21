//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  09 Creating an input attachment

#include "../CH04/S05_Creating_an_image.h"
#include "../CH04/S06_Allocating_and_binding_memory_object_to_an_image.h"
#include "../CH04/S08_Creating_an_image_view.h"
#include "S09_Creating_an_input_attachment.h"

namespace VKCookbook {

    bool CreateInputAttachment( VkPhysicalDevice     physical_device,
                                VkDevice             logical_device,
                                VkImageType          type,
                                VkFormat             format,
                                VkExtent3D           size,
                                VkImageUsageFlags    usage,
                                VkImageViewType      view_type,
                                VkImageAspectFlags   aspect,
                                VkImage            & input_attachment,
                                VkDeviceMemory     & memory_object,
                                VkImageView        & input_attachment_image_view ) {
        VkFormatProperties format_properties;
        vkGetPhysicalDeviceFormatProperties( physical_device, format, &format_properties );
        if( (aspect & VK_IMAGE_ASPECT_COLOR_BIT) &&
            !(format_properties.optimalTilingFeatures & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT) ) {
            std::cout << "Provided format is not supported for an input attachment." << std::endl;
            return false;
        }
        if( (aspect & (VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_DEPTH_BIT)) &&
            !(format_properties.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) ) {
            std::cout << "Provided format is not supported for an input attachment." << std::endl;
            return false;
        }

        if( !CreateImage( logical_device, type, format, size, 1, 1, VK_SAMPLE_COUNT_1_BIT, usage | VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT, false, input_attachment ) ) {
            return false;
        }

        if( !AllocateAndBindMemoryObjectToImage( physical_device, logical_device, input_attachment, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
            return false;
        }

        if( !CreateImageView( logical_device, input_attachment, view_type, format, aspect, input_attachment_image_view ) ) {
            return false;
        }
        return true;
    }

}
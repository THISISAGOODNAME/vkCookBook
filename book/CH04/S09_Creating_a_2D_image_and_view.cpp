//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  09 Creating a 2D image and view

#include "S05_Creating_an_image.h"
#include "S06_Allocating_and_binding_memory_object_to_an_image.h"
#include "S08_Creating_an_image_view.h"
#include "S09_Creating_a_2D_image_and_view.h"

namespace VKCookbook {

    bool Create2DImageAndView( VkPhysicalDevice        physical_device,
                               VkDevice                logical_device,
                               VkFormat                format,
                               VkExtent2D              size,
                               uint32_t                num_mipmaps,
                               uint32_t                num_layers,
                               VkSampleCountFlagBits   samples,
                               VkImageUsageFlags       usage,
                               VkImageAspectFlags      aspect,
                               VkImage               & image,
                               VkDeviceMemory        & memory_object,
                               VkImageView           & image_view ) {
        if( !CreateImage( logical_device, VK_IMAGE_TYPE_2D, format, { size.width, size.height, 1 }, num_mipmaps, num_layers, samples, usage, false, image ) ) {
            return false;
        }

        if( !AllocateAndBindMemoryObjectToImage( physical_device, logical_device, image, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
            return false;
        }

        if( !CreateImageView( logical_device, image, VK_IMAGE_VIEW_TYPE_2D, format, aspect, image_view ) ) {
            return false;
        }

        return true;
    }

}
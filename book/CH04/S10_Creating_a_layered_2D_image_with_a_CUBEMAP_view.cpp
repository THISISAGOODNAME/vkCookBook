//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  10 Creating a layered 2D image with a CUBEMAP view

#include "S05_Creating_an_image.h"
#include "S06_Allocating_and_binding_memory_object_to_an_image.h"
#include "S08_Creating_an_image_view.h"
#include "S10_Creating_a_layered_2D_image_with_a_CUBEMAP_view.h"

namespace VKCookbook {

    bool CreateLayered2DImageWithCubemapView( VkPhysicalDevice    physical_device,
                                              VkDevice            logical_device,
                                              uint32_t            size,
                                              uint32_t            num_mipmaps,
                                              VkImageUsageFlags   usage,
                                              VkImageAspectFlags  aspect,
                                              VkImage           & image,
                                              VkDeviceMemory    & memory_object,
                                              VkImageView       & image_view ) {
        if( !CreateImage( logical_device, VK_IMAGE_TYPE_2D, VK_FORMAT_R8G8B8A8_UNORM, { size, size, 1 }, num_mipmaps, 6, VK_SAMPLE_COUNT_1_BIT, usage, true, image ) ) {
            return false;
        }

        if( !AllocateAndBindMemoryObjectToImage( physical_device, logical_device, image, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
            return false;
        }

        if( !CreateImageView( logical_device, image, VK_IMAGE_VIEW_TYPE_CUBE, VK_FORMAT_R8G8B8A8_UNORM, aspect, image_view ) ) {
            return false;
        }

        return true;
    }

}

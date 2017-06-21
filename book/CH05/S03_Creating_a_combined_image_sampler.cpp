//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  03 Creating a combined image sampler

#include "S01_Creating_a_sampler.h"
#include "S02_Creating_a_sampled_image.h"
#include "S03_Creating_a_combined_image_sampler.h"

namespace VKCookbook {

    bool CreateCombinedImageSampler( VkPhysicalDevice       physical_device,
                                     VkDevice               logical_device,
                                     VkImageType            type,
                                     VkFormat               format,
                                     VkExtent3D             size,
                                     uint32_t               num_mipmaps,
                                     uint32_t               num_layers,
                                     VkImageUsageFlags      usage,
                                     VkImageViewType        view_type,
                                     VkImageAspectFlags     aspect,
                                     VkFilter               mag_filter,
                                     VkFilter               min_filter,
                                     VkSamplerMipmapMode    mipmap_mode,
                                     VkSamplerAddressMode   u_address_mode,
                                     VkSamplerAddressMode   v_address_mode,
                                     VkSamplerAddressMode   w_address_mode,
                                     float                  lod_bias,
                                     bool                   anisotropy_enable,
                                     float                  max_anisotropy,
                                     bool                   compare_enable,
                                     VkCompareOp            compare_operator,
                                     float                  min_lod,
                                     float                  max_lod,
                                     VkBorderColor          border_color,
                                     bool                   unnormalized_coords,
                                     VkSampler            & sampler,
                                     VkImage              & sampled_image,
                                     VkDeviceMemory       & memory_object,
                                     VkImageView          & sampled_image_view ) {
        if( !CreateSampler( logical_device, mag_filter, min_filter, mipmap_mode, u_address_mode, v_address_mode, w_address_mode, lod_bias, anisotropy_enable, max_anisotropy, compare_enable, compare_operator, min_lod, max_lod, border_color, unnormalized_coords, sampler ) ) {
            return false;
        }

        bool linear_filtering = (mag_filter == VK_FILTER_LINEAR) || (min_filter == VK_FILTER_LINEAR) || (mipmap_mode == VK_SAMPLER_MIPMAP_MODE_LINEAR);
        if( !CreateSampledImage( physical_device, logical_device, type, format, size, num_mipmaps, num_layers, usage, view_type, aspect, linear_filtering, sampled_image, memory_object, sampled_image_view ) ) {
            return false;
        }
        return true;
    }

}
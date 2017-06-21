//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  03 Creating a combined image sampler

#ifndef VKCOOKBOOK_S03_CREATING_A_COMBINED_IMAGE_SAMPLER_H
#define VKCOOKBOOK_S03_CREATING_A_COMBINED_IMAGE_SAMPLER_H

#include "Common.h"

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
                                     VkImageView          & sampled_image_view );

};


#endif //VKCOOKBOOK_S03_CREATING_A_COMBINED_IMAGE_SAMPLER_H

//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  01 Creating a sampler

#include "S01_Creating_a_sampler.h"

namespace VKCookbook {

    bool CreateSampler( VkDevice               logical_device,
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
                        VkSampler            & sampler ) {
        VkSamplerCreateInfo sampler_create_info = {
                VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,    // VkStructureType          sType
                nullptr,                                  // const void             * pNext
                0,                                        // VkSamplerCreateFlags     flags
                mag_filter,                               // VkFilter                 magFilter
                min_filter,                               // VkFilter                 minFilter
                mipmap_mode,                              // VkSamplerMipmapMode      mipmapMode
                u_address_mode,                           // VkSamplerAddressMode     addressModeU
                v_address_mode,                           // VkSamplerAddressMode     addressModeV
                w_address_mode,                           // VkSamplerAddressMode     addressModeW
                lod_bias,                                 // float                    mipLodBias
                anisotropy_enable,                        // VkBool32                 anisotropyEnable
                max_anisotropy,                           // float                    maxAnisotropy
                compare_enable,                           // VkBool32                 compareEnable
                compare_operator,                         // VkCompareOp              compareOp
                min_lod,                                  // float                    minLod
                max_lod,                                  // float                    maxLod
                border_color,                             // VkBorderColor            borderColor
                unnormalized_coords                       // VkBool32                 unnormalizedCoordinates
        };

        VkResult result = vkCreateSampler( logical_device, &sampler_create_info, nullptr, &sampler );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create sampler." << std::endl;
            return false;
        }
        return true;
    }

}
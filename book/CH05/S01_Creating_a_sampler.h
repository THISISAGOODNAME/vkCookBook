//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  01 Creating a sampler

#include "Common.h"

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
                        VkSampler            & sampler );

};


#endif //VKCOOKBOOK_S01_CREATING_A_SAMPLER_H

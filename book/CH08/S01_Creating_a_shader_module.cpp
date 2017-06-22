//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  01 Creating a shader module

#include "S01_Creating_a_shader_module.h"

namespace VKCookbook {

    bool CreateShaderModule( VkDevice                           logical_device,
                             std::vector<unsigned char> const & source_code,
                             VkShaderModule                   & shader_module ) {
        VkShaderModuleCreateInfo shader_module_create_info = {
                VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,              // VkStructureType              sType
                nullptr,                                                  // const void                 * pNext
                0,                                                        // VkShaderModuleCreateFlags    flags
                source_code.size(),                                       // size_t                       codeSize
                reinterpret_cast<uint32_t const *>(source_code.data())    // const uint32_t             * pCode
        };

        VkResult result = vkCreateShaderModule( logical_device, &shader_module_create_info, nullptr, &shader_module );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not create a shader module." << std::endl;
            return false;
        }
        return true;
    }

}
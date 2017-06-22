//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  20 Creating a pipeline layout with a combined image sampler, a buffer and push constant ranges

#include "../CH05/S10_Creating_a_descriptor_set_layout.h"
#include "S12_Creating_a_pipeline_layout.h"
#include "S20_Creating_a_pipeline_layout_with_a_combined_image_sampler_a_buffer_and_push_constant_ranges.h"

namespace VKCookbook {

    bool CreatePipelineLayoutWithCombinedImageSamplerBufferAndPushConstantRanges( VkDevice                                 logical_device,
                                                                                  std::vector<VkPushConstantRange> const & push_constant_ranges,
                                                                                  VkDescriptorSetLayout                  & descriptor_set_layout,
                                                                                  VkPipelineLayout                       & pipeline_layout ){
        std::vector<VkDescriptorSetLayoutBinding> descriptor_set_layout_bindings = {
                {
                        0,                                  // uint32_t               binding
                        VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE,   // VkDescriptorType       descriptorType
                        1,                                  // uint32_t               descriptorCount
                        VK_SHADER_STAGE_FRAGMENT_BIT,       // VkShaderStageFlags     stageFlags
                        nullptr                             // const VkSampler      * pImmutableSamplers
                },
                {
                        1,                                  // uint32_t               binding
                        VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,  // VkDescriptorType       descriptorType
                        1,                                  // uint32_t               descriptorCount
                        VK_SHADER_STAGE_VERTEX_BIT,         // VkShaderStageFlags     stageFlags
                        nullptr                             // const VkSampler      * pImmutableSamplers
                }
        };

        if( !CreateDescriptorSetLayout( logical_device, descriptor_set_layout_bindings, descriptor_set_layout ) ) {
            return false;
        }

        if( !CreatePipelineLayout( logical_device, { descriptor_set_layout }, push_constant_ranges, pipeline_layout ) ) {
            return false;
        }
        return true;
    }

}
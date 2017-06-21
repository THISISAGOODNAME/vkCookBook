//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 05 Descriptor Sets
// Recipe:  13 Updating descriptor sets

#include "S13_Updating_descriptor_sets.h"

namespace VKCookbook {

    void UpdateDescriptorSets( VkDevice                                       logical_device,
                               std::vector<ImageDescriptorInfo> const       & image_descriptor_infos,
                               std::vector<BufferDescriptorInfo> const      & buffer_descriptor_infos,
                               std::vector<TexelBufferDescriptorInfo> const & texel_buffer_descriptor_infos,
                               std::vector<CopyDescriptorInfo> const        & copy_descriptor_infos ) {
        std::vector<VkWriteDescriptorSet> write_descriptors;
        std::vector<VkCopyDescriptorSet> copy_descriptors;

        // image descriptors
        for( auto & image_descriptor : image_descriptor_infos ) {
            write_descriptors.push_back( {
                                                 VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,                                 // VkStructureType                  sType
                                                 nullptr,                                                                // const void                     * pNext
                                                 image_descriptor.TargetDescriptorSet,                                   // VkDescriptorSet                  dstSet
                                                 image_descriptor.TargetDescriptorBinding,                               // uint32_t                         dstBinding
                                                 image_descriptor.TargetArrayElement,                                    // uint32_t                         dstArrayElement
                                                 static_cast<uint32_t>(image_descriptor.ImageInfos.size()),              // uint32_t                         descriptorCount
                                                 image_descriptor.TargetDescriptorType,                                  // VkDescriptorType                 descriptorType
                                                 image_descriptor.ImageInfos.data(),                                     // const VkDescriptorImageInfo    * pImageInfo
                                                 nullptr,                                                                // const VkDescriptorBufferInfo   * pBufferInfo
                                                 nullptr                                                                 // const VkBufferView             * pTexelBufferView
                                         } );
        }

        // buffer descriptors
        for( auto & buffer_descriptor : buffer_descriptor_infos ) {
            write_descriptors.push_back( {
                                                 VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,                                 // VkStructureType                  sType
                                                 nullptr,                                                                // const void                     * pNext
                                                 buffer_descriptor.TargetDescriptorSet,                                  // VkDescriptorSet                  dstSet
                                                 buffer_descriptor.TargetDescriptorBinding,                              // uint32_t                         dstBinding
                                                 buffer_descriptor.TargetArrayElement,                                   // uint32_t                         dstArrayElement
                                                 static_cast<uint32_t>(buffer_descriptor.BufferInfos.size()),            // uint32_t                         descriptorCount
                                                 buffer_descriptor.TargetDescriptorType,                                 // VkDescriptorType                 descriptorType
                                                 nullptr,                                                                // const VkDescriptorImageInfo    * pImageInfo
                                                 buffer_descriptor.BufferInfos.data(),                                   // const VkDescriptorBufferInfo   * pBufferInfo
                                                 nullptr                                                                 // const VkBufferView             * pTexelBufferView
                                         } );
        }

        // texel buffer descriptors
        for( auto & texel_buffer_descriptor : texel_buffer_descriptor_infos ) {
            write_descriptors.push_back( {
                                                 VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,                                 // VkStructureType                  sType
                                                 nullptr,                                                                // const void                     * pNext
                                                 texel_buffer_descriptor.TargetDescriptorSet,                            // VkDescriptorSet                  dstSet
                                                 texel_buffer_descriptor.TargetDescriptorBinding,                        // uint32_t                         dstBinding
                                                 texel_buffer_descriptor.TargetArrayElement,                             // uint32_t                         dstArrayElement
                                                 static_cast<uint32_t>(texel_buffer_descriptor.TexelBufferViews.size()), // uint32_t                         descriptorCount
                                                 texel_buffer_descriptor.TargetDescriptorType,                           // VkDescriptorType                 descriptorType
                                                 nullptr,                                                                // const VkDescriptorImageInfo    * pImageInfo
                                                 nullptr,                                                                // const VkDescriptorBufferInfo   * pBufferInfo
                                                 texel_buffer_descriptor.TexelBufferViews.data()                         // const VkBufferView             * pTexelBufferView
                                         } );
        }

        // copy descriptors
        for( auto & copy_descriptor : copy_descriptor_infos ) {
            copy_descriptors.push_back( {
                                                VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET,                                  // VkStructureType    sType
                                                nullptr,                                                                // const void       * pNext
                                                copy_descriptor.SourceDescriptorSet,                                    // VkDescriptorSet    srcSet
                                                copy_descriptor.SourceDescriptorBinding,                                // uint32_t           srcBinding
                                                copy_descriptor.SourceArrayElement,                                     // uint32_t           srcArrayElement
                                                copy_descriptor.TargetDescriptorSet,                                    // VkDescriptorSet    dstSet
                                                copy_descriptor.TargetDescriptorBinding,                                // uint32_t           dstBinding
                                                copy_descriptor.TargetArrayElement,                                     // uint32_t           dstArrayElement
                                                copy_descriptor.DescriptorCount                                         // uint32_t           descriptorCount
                                        } );
        }

        vkUpdateDescriptorSets( logical_device, static_cast<uint32_t>(write_descriptors.size()), write_descriptors.data(), static_cast<uint32_t>(copy_descriptors.size()), copy_descriptors.data() );
    }

}
//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  11 Mapping, updating and unmapping host-visible memory

#include "S11_Mapping_updating_and_unmapping_host_visible_memory.h"

namespace VKCookbook {

    bool MapUpdateAndUnmapHostVisibleMemory( VkDevice             logical_device,
                                             VkDeviceMemory       memory_object,
                                             VkDeviceSize         offset,
                                             VkDeviceSize         data_size,
                                             void               * data,
                                             bool                 unmap,
                                             void             * * pointer ) {
        VkResult result;
        void * local_pointer;
        result = vkMapMemory( logical_device, memory_object, offset, data_size, 0, &local_pointer );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not map memory object." << std::endl;
            return false;
        }

        std::memcpy( local_pointer, data, data_size );

        std::vector<VkMappedMemoryRange> memory_ranges = {
                {
                        VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE,  // VkStructureType    sType
                        nullptr,                                // const void       * pNext
                        memory_object,                          // VkDeviceMemory     memory
                        offset,                                 // VkDeviceSize       offset
                        VK_WHOLE_SIZE                           // VkDeviceSize       size
                }
        };

        result = vkFlushMappedMemoryRanges( logical_device, static_cast<uint32_t>(memory_ranges.size()), memory_ranges.data() );
        if( VK_SUCCESS != result ) {
            std::cout << "Could not flush mapped memory." << std::endl;
            return false;
        }

        if( unmap ) {
            vkUnmapMemory( logical_device, memory_object );
        } else if( nullptr != pointer ) {
            *pointer = local_pointer;
        }

        return true;
    }

}
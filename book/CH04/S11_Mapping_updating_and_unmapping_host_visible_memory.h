//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  11 Mapping, updating and unmapping host-visible memory

#ifndef VKCOOKBOOK_S11_MAPPING_UPDATING_AND_UNMAPPING_HOST_VISIBLE_MEMORY_H
#define VKCOOKBOOK_S11_MAPPING_UPDATING_AND_UNMAPPING_HOST_VISIBLE_MEMORY_H

#include "Common.h"

namespace VKCookbook {

    bool MapUpdateAndUnmapHostVisibleMemory( VkDevice             logical_device,
                                             VkDeviceMemory       memory_object,
                                             VkDeviceSize         offset,
                                             VkDeviceSize         data_size,
                                             void               * data,
                                             bool                 unmap,
                                             void             * * pointer );

};


#endif //VKCOOKBOOK_S11_MAPPING_UPDATING_AND_UNMAPPING_HOST_VISIBLE_MEMORY_H

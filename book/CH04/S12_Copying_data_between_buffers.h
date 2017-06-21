//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  12 Copying data between buffers

#ifndef VKCOOKBOOK_S12_COPYING_DATA_BETWEEN_BUFFERS_H
#define VKCOOKBOOK_S12_COPYING_DATA_BETWEEN_BUFFERS_H

#include "Common.h"

namespace VKCookbook {

    void CopyDataBetweenBuffers( VkCommandBuffer           command_buffer,
                                 VkBuffer                  source_buffer,
                                 VkBuffer                  destination_buffer,
                                 std::vector<VkBufferCopy> regions );

};


#endif //VKCOOKBOOK_S12_COPYING_DATA_BETWEEN_BUFFERS_H

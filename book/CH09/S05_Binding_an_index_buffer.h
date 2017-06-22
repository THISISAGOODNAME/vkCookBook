//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  05 Binding an index buffer

#ifndef VKCOOKBOOK_S05_BINDING_AN_INDEX_BUFFER_H
#define VKCOOKBOOK_S05_BINDING_AN_INDEX_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    void BindIndexBuffer( VkCommandBuffer   command_buffer,
                          VkBuffer          buffer,
                          VkDeviceSize      memory_offset,
                          VkIndexType       index_type );

};


#endif //VKCOOKBOOK_S05_BINDING_AN_INDEX_BUFFER_H

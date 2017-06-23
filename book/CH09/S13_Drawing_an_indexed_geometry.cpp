//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  13 Drawing an indexed geometry

#include "S13_Drawing_an_indexed_geometry.h"

namespace VKCookbook {

    void DrawIndexedGeometry( VkCommandBuffer command_buffer,
                              uint32_t        index_count,
                              uint32_t        instance_count,
                              uint32_t        first_index,
                              uint32_t        vertex_offset,
                              uint32_t        first_instance ){
        vkCmdDrawIndexed( command_buffer, index_count, instance_count, first_index, vertex_offset, first_instance );
    }

}
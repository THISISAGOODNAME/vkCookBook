//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  13 Drawing an indexed geometry

#ifndef VKCOOKBOOK_S13_DRAWING_AN_INDEXED_GEOMETRY_H
#define VKCOOKBOOK_S13_DRAWING_AN_INDEXED_GEOMETRY_H

#include "Common.h"

namespace VKCookbook {

    void DrawIndexedGeometry( VkCommandBuffer command_buffer,
                              uint32_t        index_count,
                              uint32_t        instance_count,
                              uint32_t        first_index,
                              uint32_t        vertex_offset,
                              uint32_t        first_instance );

};


#endif //VKCOOKBOOK_S13_DRAWING_AN_INDEXED_GEOMETRY_H

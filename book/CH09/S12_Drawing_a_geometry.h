//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  12 Drawing a geometry

#ifndef VKCOOKBOOK_S12_DRAWING_A_GEOMETRY_H
#define VKCOOKBOOK_S12_DRAWING_A_GEOMETRY_H

#include "Common.h"

namespace VKCookbook {

    void DrawGeometry( VkCommandBuffer command_buffer,
                       uint32_t        vertex_count,
                       uint32_t        instance_count,
                       uint32_t        first_vertex,
                       uint32_t        first_instance );

};


#endif //VKCOOKBOOK_S12_DRAWING_A_GEOMETRY_H

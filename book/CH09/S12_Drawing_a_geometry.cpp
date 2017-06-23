//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  12 Drawing a geometry

#include "S12_Drawing_a_geometry.h"

#include "Common.h"

namespace VKCookbook {

    void DrawGeometry( VkCommandBuffer command_buffer,
                       uint32_t        vertex_count,
                       uint32_t        instance_count,
                       uint32_t        first_vertex,
                       uint32_t        first_instance ){
        vkCmdDraw( command_buffer, vertex_count, instance_count, first_vertex, first_instance );
    }

}
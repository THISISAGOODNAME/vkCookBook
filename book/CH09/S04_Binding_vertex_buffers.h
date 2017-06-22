//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  04 Binding vertex buffers

#ifndef VKCOOKBOOK_S04_BINDING_VERTEX_BUFFERS_H
#define VKCOOKBOOK_S04_BINDING_VERTEX_BUFFERS_H

#include "Common.h"

namespace VKCookbook {

    struct VertexBufferParameters {
        VkBuffer      Buffer;
        VkDeviceSize  MemoryOffset;
    };

    void BindVertexBuffers( VkCommandBuffer                             command_buffer,
                            uint32_t                                    first_binding,
                            std::vector<VertexBufferParameters> const & buffers_parameters );

};


#endif //VKCOOKBOOK_S04_BINDING_VERTEX_BUFFERS_H

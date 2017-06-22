//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  04 Binding vertex buffers

#include "S04_Binding_vertex_buffers.h"

namespace VKCookbook {

    void BindVertexBuffers( VkCommandBuffer                             command_buffer,
                            uint32_t                                    first_binding,
                            std::vector<VertexBufferParameters> const & buffers_parameters ){
        if( buffers_parameters.size() > 0 ) {
            std::vector<VkBuffer>     buffers;
            std::vector<VkDeviceSize> offsets;
            for( auto & buffer_parameters : buffers_parameters ) {
                buffers.push_back( buffer_parameters.Buffer );
                offsets.push_back( buffer_parameters.MemoryOffset );
            }
            vkCmdBindVertexBuffers( command_buffer, first_binding, static_cast<uint32_t>(buffers_parameters.size()), buffers.data(), offsets.data() );
        }
    }

}
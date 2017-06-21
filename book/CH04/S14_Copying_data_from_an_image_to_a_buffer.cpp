//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  14 Copying data from an image to a buffer

#include "S14_Copying_data_from_an_image_to_a_buffer.h"

namespace VKCookbook {

    void CopyDataFromImageToBuffer( VkCommandBuffer                command_buffer,
                                    VkImage                        source_image,
                                    VkImageLayout                  image_layout,
                                    VkBuffer                       destination_buffer,
                                    std::vector<VkBufferImageCopy> regions ) {
        if( regions.size() > 0 ) {
            vkCmdCopyImageToBuffer( command_buffer, source_image, image_layout, destination_buffer, static_cast<uint32_t>(regions.size()), regions.data() );
        }
    }

}
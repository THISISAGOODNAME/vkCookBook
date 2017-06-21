//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  13 Copying data from a buffer to an image

#include "S13_Copying_data_from_a_buffer_to_an_image.h"

namespace VKCookbook {

    void CopyDataFromBufferToImage( VkCommandBuffer                command_buffer,
                                    VkBuffer                       source_buffer,
                                    VkImage                        destination_image,
                                    VkImageLayout                  image_layout,
                                    std::vector<VkBufferImageCopy> regions ) {
        if( regions.size() > 0 ) {
            vkCmdCopyBufferToImage( command_buffer, source_buffer, destination_image, image_layout, static_cast<uint32_t>(regions.size()), regions.data() );
        }
    }

}
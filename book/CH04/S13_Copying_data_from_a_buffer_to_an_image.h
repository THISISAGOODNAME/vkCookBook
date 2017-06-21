//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  13 Copying data from a buffer to an image

#ifndef VKCOOKBOOK_S13_COPYING_DATA_FROM_A_BUFFER_TO_AN_IMAGE_H
#define VKCOOKBOOK_S13_COPYING_DATA_FROM_A_BUFFER_TO_AN_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    void CopyDataFromBufferToImage( VkCommandBuffer                command_buffer,
                                    VkBuffer                       source_buffer,
                                    VkImage                        destination_image,
                                    VkImageLayout                  image_layout,
                                    std::vector<VkBufferImageCopy> regions );

};


#endif //VKCOOKBOOK_S13_COPYING_DATA_FROM_A_BUFFER_TO_AN_IMAGE_H

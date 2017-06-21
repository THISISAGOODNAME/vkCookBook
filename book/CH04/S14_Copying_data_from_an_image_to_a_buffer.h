//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  14 Copying data from an image to a buffer

#ifndef VKCOOKBOOK_S14_COPYING_DATA_FROM_AN_IMAGE_TO_A_BUFFER_H
#define VKCOOKBOOK_S14_COPYING_DATA_FROM_AN_IMAGE_TO_A_BUFFER_H

#include "Common.h"

namespace VKCookbook {

    void CopyDataFromImageToBuffer( VkCommandBuffer                command_buffer,
                                    VkImage                        source_image,
                                    VkImageLayout                  image_layout,
                                    VkBuffer                       destination_buffer,
                                    std::vector<VkBufferImageCopy> regions );

};


#endif //VKCOOKBOOK_S14_COPYING_DATA_FROM_AN_IMAGE_TO_A_BUFFER_H

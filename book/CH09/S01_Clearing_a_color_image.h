//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  01 Clearing a color image

#ifndef VKCOOKBOOK_S01_CLEARING_A_COLOR_IMAGE_H
#define VKCOOKBOOK_S01_CLEARING_A_COLOR_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    void ClearColorImage( VkCommandBuffer                              command_buffer,
                          VkImage                                      image,
                          VkImageLayout                                image_layout,
                          std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                          VkClearColorValue                          & clear_color );

};


#endif //VKCOOKBOOK_S01_CLEARING_A_COLOR_IMAGE_H

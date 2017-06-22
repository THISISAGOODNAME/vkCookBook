//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  01 Clearing a color image

#include "S01_Clearing_a_color_image.h"

namespace VKCookbook {

    void ClearColorImage( VkCommandBuffer                              command_buffer,
                          VkImage                                      image,
                          VkImageLayout                                image_layout,
                          std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                          VkClearColorValue                          & clear_color ){
        vkCmdClearColorImage( command_buffer, image, image_layout, &clear_color, static_cast<uint32_t>(image_subresource_ranges.size()), image_subresource_ranges.data() );
    }

}
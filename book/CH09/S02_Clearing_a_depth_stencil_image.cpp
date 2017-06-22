//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  02 Clearing a depth-stencil image

#include "S02_Clearing_a_depth_stencil_image.h"

namespace VKCookbook {

    void ClearDepthStencilImage( VkCommandBuffer                              command_buffer,
                                 VkImage                                      image,
                                 VkImageLayout                                image_layout,
                                 std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                                 VkClearDepthStencilValue                   & clear_value ){
        vkCmdClearDepthStencilImage( command_buffer, image, image_layout, &clear_value, static_cast<uint32_t>(image_subresource_ranges.size()), image_subresource_ranges.data() );
    }

}
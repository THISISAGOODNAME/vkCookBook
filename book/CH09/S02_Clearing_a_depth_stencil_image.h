//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  02 Clearing a depth-stencil image

#ifndef VKCOOKBOOK_S02_CLEARING_A_DEPTH_STENCIL_IMAGE_H
#define VKCOOKBOOK_S02_CLEARING_A_DEPTH_STENCIL_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    void ClearDepthStencilImage( VkCommandBuffer                              command_buffer,
                                 VkImage                                      image,
                                 VkImageLayout                                image_layout,
                                 std::vector<VkImageSubresourceRange> const & image_subresource_ranges,
                                 VkClearDepthStencilValue                   & clear_value );

};


#endif //VKCOOKBOOK_S02_CLEARING_A_DEPTH_STENCIL_IMAGE_H

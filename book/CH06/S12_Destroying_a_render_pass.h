//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  12 Destroying a render pass

#ifndef VKCOOKBOOK_S12_DESTROYING_A_RENDER_PASS_H
#define VKCOOKBOOK_S12_DESTROYING_A_RENDER_PASS_H

#include "Common.h"

namespace VKCookbook {

    void DestroyRenderPass( VkDevice       logical_device,
                            VkRenderPass & render_pass );

};


#endif //VKCOOKBOOK_S12_DESTROYING_A_RENDER_PASS_H

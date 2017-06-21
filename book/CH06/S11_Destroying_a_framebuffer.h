//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  11 Destroying a framebuffer

#ifndef VKCOOKBOOK_S11_DESTROYING_A_FRAMEBUFFER_H
#define VKCOOKBOOK_S11_DESTROYING_A_FRAMEBUFFER_H

#include "Common.h"

namespace VKCookbook {

    void DestroyFramebuffer( VkDevice        logical_device,
                             VkFramebuffer & framebuffer );

};


#endif //VKCOOKBOOK_S11_DESTROYING_A_FRAMEBUFFER_H

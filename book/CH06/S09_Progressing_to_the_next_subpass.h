//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  09 Progressing to the next subpass

#ifndef VKCOOKBOOK_S09_PROGRESSING_TO_THE_NEXT_SUBPASS_H
#define VKCOOKBOOK_S09_PROGRESSING_TO_THE_NEXT_SUBPASS_H

#include "Common.h"

namespace VKCookbook {

    void ProgressToTheNextSubpass( VkCommandBuffer   command_buffer,
                                   VkSubpassContents subpass_contents );

};


#endif //VKCOOKBOOK_S09_PROGRESSING_TO_THE_NEXT_SUBPASS_H

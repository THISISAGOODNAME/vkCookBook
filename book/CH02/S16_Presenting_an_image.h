//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  16 Presenting an image

#ifndef VKCOOKBOOK_S16_PRESENTING_AN_IMAGE_H
#define VKCOOKBOOK_S16_PRESENTING_AN_IMAGE_H

#include "Common.h"

namespace VKCookbook {

    struct PresentInfo {
        VkSwapchainKHR  Swapchain;
        uint32_t        ImageIndex;
    };

    bool PresentImage( VkQueue                  queue,
                       std::vector<VkSemaphore> rendering_semaphores,
                       std::vector<PresentInfo> images_to_present );

};


#endif //VKCOOKBOOK_S16_PRESENTING_AN_IMAGE_H

//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 04 Resources and Memory
// Recipe:  07 Setting an image memory barrier

#ifndef VKCOOKBOOK_S07_SETTING_AN_IMAGE_MEMORY_BARRIER_H
#define VKCOOKBOOK_S07_SETTING_AN_IMAGE_MEMORY_BARRIER_H

#include "Common.h"

namespace VKCookbook {

    struct ImageTransition {
        VkImage             Image;
        VkAccessFlags       CurrentAccess;
        VkAccessFlags       NewAccess;
        VkImageLayout       CurrentLayout;
        VkImageLayout       NewLayout;
        uint32_t            CurrentQueueFamily;
        uint32_t            NewQueueFamily;
        VkImageAspectFlags  Aspect;
    };

    void SetImageMemoryBarrier( VkCommandBuffer              command_buffer,
                                VkPipelineStageFlags         generating_stages,
                                VkPipelineStageFlags         consuming_stages,
                                std::vector<ImageTransition> image_transitions );

};


#endif //VKCOOKBOOK_S07_SETTING_AN_IMAGE_MEMORY_BARRIER_H

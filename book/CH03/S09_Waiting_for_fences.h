//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  09 Waiting for fences

#ifndef VKCOOKBOOK_S09_WAITING_FOR_FENCES_H
#define VKCOOKBOOK_S09_WAITING_FOR_FENCES_H

#include "Common.h"

namespace VKCookbook {

    bool WaitForFences( VkDevice                     logical_device,
                        std::vector<VkFence> const & fences,
                        VkBool32                     wait_for_all,
                        uint64_t                     timeout );

};


#endif //VKCOOKBOOK_S09_WAITING_FOR_FENCES_H

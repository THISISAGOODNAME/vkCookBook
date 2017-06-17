//
// Created by aicdg on 2017/6/17.
//

#ifndef VKCOOKBOOK_S14_SELECTING_INDEX_OF_A_QUEUE_FAMILY_WITH_DESIRED_CAPABILITIES_H
#define VKCOOKBOOK_S14_SELECTING_INDEX_OF_A_QUEUE_FAMILY_WITH_DESIRED_CAPABILITIES_H

#include "Common.h"

namespace VKCookbook {

    bool SelectIndexOfQueueFamilyWithDesiredCapabilities( VkPhysicalDevice   physical_device,
                                                          VkQueueFlags       desired_capabilities,
                                                          uint32_t         & queue_family_index );

};


#endif //VKCOOKBOOK_S14_SELECTING_INDEX_OF_A_QUEUE_FAMILY_WITH_DESIRED_CAPABILITIES_H

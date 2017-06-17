//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  14 Selecting index of a queue family with desired capabilities

#ifndef VKCOOKBOOK_S14_SELECTING_INDEX_OF_A_QUEUE_FAMILY_WITH_DESIRED_CAPABILITIES_H
#define VKCOOKBOOK_S14_SELECTING_INDEX_OF_A_QUEUE_FAMILY_WITH_DESIRED_CAPABILITIES_H

#include "Common.h"

namespace VKCookbook {

    bool SelectIndexOfQueueFamilyWithDesiredCapabilities( VkPhysicalDevice   physical_device,
                                                          VkQueueFlags       desired_capabilities,
                                                          uint32_t         & queue_family_index );

};


#endif //VKCOOKBOOK_S14_SELECTING_INDEX_OF_A_QUEUE_FAMILY_WITH_DESIRED_CAPABILITIES_H

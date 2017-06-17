//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  15 Creating a logical device

#ifndef VKCOOKBOOK_S15_CREATING_A_LOGICAL_DEVICE_H
#define VKCOOKBOOK_S15_CREATING_A_LOGICAL_DEVICE_H

#include "Common.h"

namespace VKCookbook {

    struct QueueInfo {
        uint32_t           FamilyIndex;
        std::vector<float> Priorities;
    };

    bool CreateLogicalDevice( VkPhysicalDevice                  physical_device,
                              std::vector< QueueInfo >          queue_infos,
                              std::vector<char const *> const & desired_extensions,
                              VkPhysicalDeviceFeatures        * desired_features,
                              VkDevice                        & logical_device );

};


#endif //VKCOOKBOOK_S15_CREATING_A_LOGICAL_DEVICE_H

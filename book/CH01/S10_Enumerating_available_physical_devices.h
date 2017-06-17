//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  10 Enumerating available physical devices

#ifndef VKCOOKBOOK_S10_ENUMERATING_AVAILABLE_PHYSICAL_DEVICES_H
#define VKCOOKBOOK_S10_ENUMERATING_AVAILABLE_PHYSICAL_DEVICES_H


#include "Common.h"

namespace VKCookbook {

    bool EnumerateAvailablePhysicalDevices( VkInstance                      instance,
                                            std::vector<VkPhysicalDevice> & available_devices );

};


#endif //VKCOOKBOOK_S10_ENUMERATING_AVAILABLE_PHYSICAL_DEVICES_H

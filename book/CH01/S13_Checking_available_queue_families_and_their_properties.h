//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  13 Checking available queue families and their properties

#ifndef VKCOOKBOOK_S13_CHECKING_AVAILABLE_QUEUE_FAMILIES_AND_THEIR_PROPERTIES_H
#define VKCOOKBOOK_S13_CHECKING_AVAILABLE_QUEUE_FAMILIES_AND_THEIR_PROPERTIES_H

#include "Common.h"

namespace VKCookbook {

    bool CheckAvailableQueueFamiliesAndTheirProperties( VkPhysicalDevice                       physical_device,
                                                        std::vector<VkQueueFamilyProperties> & queue_families );

};


#endif //VKCOOKBOOK_S13_CHECKING_AVAILABLE_QUEUE_FAMILIES_AND_THEIR_PROPERTIES_H

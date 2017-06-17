//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  12 Getting features and properties of a physical device

#ifndef VKCOOKBOOK_S12_GETTING_FEATURES_AND_PROPERTIES_OF_A_PHYSICAL_DEVICE_H
#define VKCOOKBOOK_S12_GETTING_FEATURES_AND_PROPERTIES_OF_A_PHYSICAL_DEVICE_H

#include "Common.h"

namespace VKCookbook {

    void GetFeaturesAndPropertiesOfPhysicalDevice( VkPhysicalDevice             physical_device,
                                                   VkPhysicalDeviceFeatures   & device_features,
                                                   VkPhysicalDeviceProperties & device_properties );

};


#endif //VKCOOKBOOK_S12_GETTING_FEATURES_AND_PROPERTIES_OF_A_PHYSICAL_DEVICE_H

//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  12 Getting features and properties of a physical device

#include "S12_Getting_features_and_properties_of_a_physical_device.h"

namespace VKCookbook {

    void GetFeaturesAndPropertiesOfPhysicalDevice( VkPhysicalDevice             physical_device,
                                                   VkPhysicalDeviceFeatures   & device_features,
                                                   VkPhysicalDeviceProperties & device_properties ) {
        vkGetPhysicalDeviceFeatures( physical_device, &device_features );

        vkGetPhysicalDeviceProperties( physical_device, &device_properties );
    }

}
//
// Created by aicdg on 2017/6/17.
//


//
// Chapter: 01 Instance and Devices
// Recipe:  11 Checking available device extensions

#ifndef VKCOOKBOOK_S11_CHECKING_AVAILABLE_DEVICE_EXTENSIONS_H
#define VKCOOKBOOK_S11_CHECKING_AVAILABLE_DEVICE_EXTENSIONS_H

#include "Common.h"

namespace VKCookbook {

    bool CheckAvailableDeviceExtensions( VkPhysicalDevice                     physical_device,
                                         std::vector<VkExtensionProperties> & available_extensions );

};


#endif //VKCOOKBOOK_S11_CHECKING_AVAILABLE_DEVICE_EXTENSIONS_H

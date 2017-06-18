//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  04 Creating a logical device with WSI extensions enabled

#ifndef VKCOOKBOOK_S04_CREATING_A_LOGICAL_DEVICE_WITH_WSI_EXTENSIONS_ENABLED_H
#define VKCOOKBOOK_S04_CREATING_A_LOGICAL_DEVICE_WITH_WSI_EXTENSIONS_ENABLED_H

#include "../CH01/S15_Creating_a_logical_device.h"

namespace VKCookbook {

    bool CreateLogicalDeviceWithWsiExtensionsEnabled( VkPhysicalDevice            physical_device,
                                                      std::vector< QueueInfo >    queue_infos,
                                                      std::vector<char const *> & desired_extensions,
                                                      VkPhysicalDeviceFeatures  * desired_features,
                                                      VkDevice                  & logical_device );

};


#endif //VKCOOKBOOK_S04_CREATING_A_LOGICAL_DEVICE_WITH_WSI_EXTENSIONS_ENABLED_H

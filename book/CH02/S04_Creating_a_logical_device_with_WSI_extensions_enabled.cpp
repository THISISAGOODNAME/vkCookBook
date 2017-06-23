//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  04 Creating a logical device with WSI extensions enabled

#include "S04_Creating_a_logical_device_with_WSI_extensions_enabled.h"

namespace VKCookbook {

    bool CreateLogicalDeviceWithWsiExtensionsEnabled( VkPhysicalDevice            physical_device,
                                                      std::vector< QueueInfo >    queue_infos,
                                                      std::vector<char const *> & desired_extensions,
                                                      VkPhysicalDeviceFeatures  * desired_features,
                                                      VkDevice                  & logical_device ) {
        desired_extensions.emplace_back( VK_KHR_SWAPCHAIN_EXTENSION_NAME );

        return CreateLogicalDevice( physical_device, queue_infos, desired_extensions, desired_features, logical_device );
    }

}
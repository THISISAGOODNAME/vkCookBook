//
// Created by aicdg on 2017/6/17.
//

#include "S11_Checking_available_device_extensions.h"
#include "S15_Creating_a_logical_device.h"

namespace VKCookbook {

    bool CreateLogicalDevice( VkPhysicalDevice                  physical_device,
                              std::vector< QueueInfo >          queue_infos,
                              std::vector<char const *> const & desired_extensions,
                              VkPhysicalDeviceFeatures        * desired_features,
                              VkDevice                        & logical_device ) {
        std::vector<VkExtensionProperties> available_extensions;
        if ( !CheckAvailableDeviceExtensions( physical_device, available_extensions ) ) {
            return false;
        }

        for ( auto & extension : desired_extensions ) {
            if ( !IsExtensionSupported( available_extensions, extension ) ) {
                std::cout << "Extension named '" << extension << "' is not supported by a physical device." << std::endl;
                return false;
            }
        }

        std::vector<VkDeviceQueueCreateInfo> queue_create_infos;
        for ( auto & info : queue_infos ) {
            queue_create_infos.push_back( {
                                                  VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,         // VkStructureType                  sType
                                                  nullptr,                                          // const void                     * pNext
                                                  0,                                                 // VkDeviceQueueCreateFlags         flags
                                                  info.FamilyIndex,                                  // uint32_t                         queueFamilyIndex
                                                  static_cast<uint32_t>(info.Priorities.size()),    // uint32_t                         queueCount
                                                  info.Priorities.data()                             // const float
                                          } );
        };

        VkDeviceCreateInfo device_create_info = {
                VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,                 // VkStructureType                  sType
                nullptr,                                            // const void                     * pNext
                0,                                                   // VkDeviceCreateFlags              flags
                static_cast<uint32_t>(queue_create_infos.size()),   // uint32_t                         queueCreateInfoCount
                queue_create_infos.data(),                           // const VkDeviceQueueCreateInfo  * pQueueCreateInfos
                0,                                                   // uint32_t                         enabledLayerCount
                nullptr,                                            // const char * const             * ppEnabledLayerNames
                static_cast<uint32_t>(desired_extensions.size()),   // uint32_t                         enabledExtensionCount
                desired_extensions.data(),                           // const char * const             * ppEnabledExtensionNames
                desired_features                                     // const VkPhysicalDeviceFeatures * pEnabledFeatures
        };

        VkResult  result = vkCreateDevice( physical_device, &device_create_info, nullptr, &logical_device );
        if ( (result != VK_SUCCESS) || (logical_device == VK_NULL_HANDLE) ) {
            std::cout << "Could not create logical device." << std::endl;
            return false;
        }

        return true;
    }

}
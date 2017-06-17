//
// Created by yangyanjun on 2017/6/13.
//

//
// Vulkan Functions

#ifndef VKCOOKBOOK_VULKANFUNCTIONS_H
#define VKCOOKBOOK_VULKANFUNCTIONS_H

//#define VK_NO_PROTOTYPES
#include <vulkan/vulkan.h>

namespace VKCookbook {

#define EXPORTED_VULKAN_FUNCTION( name ) extern PFN_##name name;
#define GLOBAL_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
#define INSTANCE_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) extern PFN_##name name;
#define DEVICE_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) extern PFN_##name name;

#include "ListOfVulkanFunctions.inl"

};


#endif //VKCOOKBOOK_VULKANFUNCTIONS_H

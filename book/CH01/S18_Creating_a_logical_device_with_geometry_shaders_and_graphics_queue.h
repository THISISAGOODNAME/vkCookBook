//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  18 Creating a logical device with geometry shaders and graphics and compute queues

#ifndef VKCOOKBOOK_S18_CREATING_A_LOGICAL_DEVICE_WITH_GEOMETRY_SHADERS_AND_GRAPHICS_QUEUE_H
#define VKCOOKBOOK_S18_CREATING_A_LOGICAL_DEVICE_WITH_GEOMETRY_SHADERS_AND_GRAPHICS_QUEUE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateLogicalDeviceWithGeometryShadersAndGraphicsAndComputeQueues( VkInstance   instance,
                                                                            VkDevice   & logical_device,
                                                                            VkQueue    & graphics_queue,
                                                                            VkQueue    & compute_queue );

};


#endif //VKCOOKBOOK_S18_CREATING_A_LOGICAL_DEVICE_WITH_GEOMETRY_SHADERS_AND_GRAPHICS_QUEUE_H

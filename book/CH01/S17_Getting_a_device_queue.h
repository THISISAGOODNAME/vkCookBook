//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  17 Getting a device queue

#ifndef VKCOOKBOOK_S17_GETTING_A_DEVICE_QUEUE_H
#define VKCOOKBOOK_S17_GETTING_A_DEVICE_QUEUE_H

#include "Common.h"

namespace VKCookbook {

    void GetDeviceQueue( VkDevice logical_device, uint32_t queue_family_index, uint32_t queue_index, VkQueue & queue );

};


#endif //VKCOOKBOOK_S17_GETTING_A_DEVICE_QUEUE_H

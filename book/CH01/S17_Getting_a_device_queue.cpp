//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  17 Getting a device queue

#include "S17_Getting_a_device_queue.h"

namespace VKCookbook {

    void GetDeviceQueue( VkDevice logical_device, uint32_t queue_family_index, uint32_t queue_index, VkQueue & queue ) {
        vkGetDeviceQueue(logical_device, queue_family_index, queue_index, &queue);
    }

}
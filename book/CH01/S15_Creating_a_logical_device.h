//
// Created by aicdg on 2017/6/17.
//

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 01 Instance and Devices
// Recipe:  15 Creating a logical device

#ifndef VKCOOKBOOK_S15_CREATING_A_LOGICAL_DEVICE_H
#define VKCOOKBOOK_S15_CREATING_A_LOGICAL_DEVICE_H

#include "Common.h"

namespace VKCookbook {

    struct QueueInfo {
        uint32_t           FamilyIndex;
        std::vector<float> Priorities;
    };

    bool CreateLogicalDevice( VkPhysicalDevice                  physical_device,
                              std::vector< QueueInfo >          queue_infos,
                              std::vector<char const *> const & desired_extensions,
                              VkPhysicalDeviceFeatures        * desired_features,
                              VkDevice                        & logical_device );

};


#endif //VKCOOKBOOK_S15_CREATING_A_LOGICAL_DEVICE_H

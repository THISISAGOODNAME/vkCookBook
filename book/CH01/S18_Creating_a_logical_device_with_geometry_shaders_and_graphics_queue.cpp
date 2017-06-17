//
// Created by aicdg on 2017/6/17.
//

//
// Chapter: 01 Instance and Devices
// Recipe:  18 Creating a logical device with geometry shaders and graphics and compute queues

#include "S10_Enumerating_available_physical_devices.h"
#include "S12_Getting_features_and_properties_of_a_physical_device.h"
#include "S14_Selecting_index_of_a_queue_family_with_desired_capabilities.h"
#include "S15_Creating_a_logical_device.h"
#include "S16_Loading_device_level_functions.h"
#include "S17_Getting_a_device_queue.h"
#include "S18_Creating_a_logical_device_with_geometry_shaders_and_graphics_queue.h"

namespace VKCookbook {

    bool CreateLogicalDeviceWithGeometryShadersAndGraphicsAndComputeQueues( VkInstance   instance,
                                                                            VkDevice   & logical_device,
                                                                            VkQueue    & graphics_queue,
                                                                            VkQueue    & compute_queue ) {
        std::vector<VkPhysicalDevice> physical_devices;
        EnumerateAvailablePhysicalDevices( instance, physical_devices );

        for( auto & physical_device : physical_devices ) {
            VkPhysicalDeviceFeatures device_features;
            VkPhysicalDeviceProperties device_properties;
            GetFeaturesAndPropertiesOfPhysicalDevice( physical_device, device_features, device_properties );

            if ( !device_features.geometryShader ) {
                continue;
            } else {
                device_features = {};
                device_features.geometryShader = VK_TRUE;
            }

            uint32_t graphics_queue_family_index;
            if ( !SelectIndexOfQueueFamilyWithDesiredCapabilities( physical_device, VK_QUEUE_GRAPHICS_BIT, graphics_queue_family_index ) ) {
                continue;
            }

            uint32_t compute_queue_family_index;
            if ( !SelectIndexOfQueueFamilyWithDesiredCapabilities( physical_device, VK_QUEUE_COMPUTE_BIT, compute_queue_family_index ) ) {
                continue;
            }

            std::vector<QueueInfo> requested_queues = { { graphics_queue_family_index, { 1.0f } } };
            if ( graphics_queue_family_index != compute_queue_family_index ) {
                requested_queues.push_back( { compute_queue_family_index, { 1.0f } }  );
            }

            if ( !CreateLogicalDevice( physical_device, requested_queues, {}, &device_features, logical_device ) ) {
                continue;
            } else {
                if ( !LoadDeviceLevelFunctions( logical_device, {} ) ) {
                    return false;
                }
                GetDeviceQueue( logical_device, graphics_queue_family_index, 0, graphics_queue );
                GetDeviceQueue( logical_device, compute_queue_family_index, 0, compute_queue );
                return true;
            }
        }

        return false;
    }

}
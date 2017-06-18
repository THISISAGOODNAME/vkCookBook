//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  05 Selecting a desired presentation mode

#include "S05_Selecting_a_desired_presentation_mode.h"

namespace VKCookbook {

    bool SelectDesiredPresentationMode( VkPhysicalDevice   physical_device,
                                        VkSurfaceKHR       presentation_surface,
                                        VkPresentModeKHR   desired_present_mode,
                                        VkPresentModeKHR & present_mode ) {
        // Enumerate supported present modes
        uint32_t present_modes_count = 0;
        VkResult result = VK_SUCCESS;

        result = vkGetPhysicalDeviceSurfacePresentModesKHR( physical_device, presentation_surface, &present_modes_count,
                                                            nullptr );
        if( (VK_SUCCESS != result) ||
            (0 == present_modes_count) ) {
            std::cout << "Could not get the number of supported present modes." << std::endl;
            return false;
        }

        std::vector<VkPresentModeKHR> present_modes( present_modes_count );
        result = vkGetPhysicalDeviceSurfacePresentModesKHR( physical_device, presentation_surface, &present_modes_count, present_modes.data() );
        if( (VK_SUCCESS != result) ||
            (0 == present_modes_count) ) {
            std::cout << "Could not enumerate present modes." << std::endl;
            return false;
        }

        // Select present mode
        for( auto & current_present_mode : present_modes ) {
            if( current_present_mode == desired_present_mode ) {
                present_mode = desired_present_mode;
                return true;
            }
        }
        std::cout << "Desired present mode is not supported. Selecting default FIFO mode." << std::endl;

        for( auto & current_present_mode : present_modes ) {
            if( current_present_mode == VK_PRESENT_MODE_FIFO_KHR ) {
                present_mode = VK_PRESENT_MODE_FIFO_KHR;
                return true;
            }
        }
        std::cout << "VK_PRESENT_MODE_FIFO_KHR is not supported though it's mandatory for all drivers!" << std::endl;

        return false;
    }

}
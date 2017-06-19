//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  11 Selecting a format of swapchain images

#include "S11_Selecting_a_format_of_swapchain_images.h"

namespace VKCookbook {

    bool SelectFormatOfSwapchainImages( VkPhysicalDevice     physical_device,
                                        VkSurfaceKHR         presentation_surface,
                                        VkSurfaceFormatKHR   desired_surface_format,
                                        VkFormat           & image_format,
                                        VkColorSpaceKHR    & image_color_space ) {
        // Enumerate supported formats
        uint32_t formats_count = 0;
        VkResult result = VK_SUCCESS;

        result = vkGetPhysicalDeviceSurfaceFormatsKHR( physical_device, presentation_surface, &formats_count, nullptr );
        if( (VK_SUCCESS != result) ||
            (0 == formats_count) ) {
            std::cout << "Could not get the number of supported surface formats." << std::endl;
            return false;
        }

        std::vector<VkSurfaceFormatKHR> surface_formats( formats_count );
        result = vkGetPhysicalDeviceSurfaceFormatsKHR( physical_device, presentation_surface, &formats_count, surface_formats.data() );
        if( (VK_SUCCESS != result) ||
            (0 == formats_count) ) {
            std::cout << "Could not enumerate supported surface formats." << std::endl;
            return false;
        }

        // Select surface format
        if( (1 == surface_formats.size()) &&
            (VK_FORMAT_UNDEFINED == surface_formats[0].format) ) {
            image_format = desired_surface_format.format;
            image_color_space = desired_surface_format.colorSpace;
            return true;
        }

        for( auto & surface_format : surface_formats ) {
            if( (desired_surface_format.format == surface_format.format) &&
                (desired_surface_format.colorSpace == surface_format.colorSpace) ) {
                image_format = desired_surface_format.format;
                image_color_space = desired_surface_format.colorSpace;
                return true;
            }
        }

        for( auto & surface_format : surface_formats ) {
            if( (desired_surface_format.format == surface_format.format) ) {
                image_format = desired_surface_format.format;
                image_color_space = surface_format.colorSpace;
                std::cout << "Desired combination of format and colorspace is not supported. Selecting other colorspace." << std::endl;
                return true;
            }
        }

        image_format = surface_formats[0].format;
        image_color_space = surface_formats[0].colorSpace;
        std::cout << "Desired format is not supported. Selecting available format - colorspace combination." << std::endl;
        return true;
    }

}
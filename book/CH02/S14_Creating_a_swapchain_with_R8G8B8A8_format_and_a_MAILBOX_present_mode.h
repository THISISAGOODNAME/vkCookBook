//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  14 Creating a swapchain with R8G8B8A8 format and a MAILBOX present mode

#ifndef VKCOOKBOOK_S14_CREATING_A_SWAPCHAIN_WITH_R8G8B8A8_FORMAT_AND_A_MAILBOX_PRESENT_MODE_H
#define VKCOOKBOOK_S14_CREATING_A_SWAPCHAIN_WITH_R8G8B8A8_FORMAT_AND_A_MAILBOX_PRESENT_MODE_H

#include "Common.h"

namespace VKCookbook {

    bool CreateSwapchainWithR8G8B8A8FormatAndMailboxPresentMode( VkPhysicalDevice       physical_device,
                                                                 VkSurfaceKHR           presentation_surface,
                                                                 VkDevice               logical_device,
                                                                 VkImageUsageFlags      swapchain_image_usage,
                                                                 VkExtent2D           & image_size,
                                                                 VkFormat             & image_format,
                                                                 VkSwapchainKHR       & old_swapchain,
                                                                 VkSwapchainKHR       & swapchain,
                                                                 std::vector<VkImage> & swapchain_images  );

};


#endif //VKCOOKBOOK_S14_CREATING_A_SWAPCHAIN_WITH_R8G8B8A8_FORMAT_AND_A_MAILBOX_PRESENT_MODE_H

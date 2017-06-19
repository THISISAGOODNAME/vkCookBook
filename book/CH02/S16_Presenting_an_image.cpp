//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  16 Presenting an image

#include "S16_Presenting_an_image.h"

namespace VKCookbook {
    bool PresentImage(VkQueue queue,
                      std::vector<VkSemaphore> rendering_semaphores,
                      std::vector<PresentInfo> images_to_present) {
        VkResult result;
        std::vector<VkSwapchainKHR> swapchains;
        std::vector<uint32_t> image_indices;

        for( auto & image_to_present : images_to_present ) {
            swapchains.emplace_back( image_to_present.Swapchain );
            image_indices.emplace_back( image_to_present.ImageIndex );
        }

        VkPresentInfoKHR present_info = {
                VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,                   // VkStructureType          sType
                nullptr,                                              // const void*              pNext
                static_cast<uint32_t>(rendering_semaphores.size()),   // uint32_t                 waitSemaphoreCount
                rendering_semaphores.data(),                          // const VkSemaphore      * pWaitSemaphores
                static_cast<uint32_t>(swapchains.size()),             // uint32_t                 swapchainCount
                swapchains.data(),                                    // const VkSwapchainKHR   * pSwapchains
                image_indices.data(),                                 // const uint32_t         * pImageIndices
                nullptr                                               // VkResult*                pResults
        };

        result = vkQueuePresentKHR( queue, &present_info );
        switch( result ) {
            case VK_SUCCESS:
                return true;
            default:
                return false;
        }
    }

}
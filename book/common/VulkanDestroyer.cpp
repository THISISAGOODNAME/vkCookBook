//
// Created by aicdg on 2017/6/14.
//


//
// VulkanDestroyer

#include "VulkanDestroyer.h"

namespace VKCookbook {

#define VK_DESTROYER_SPECIALIZATION(type, deleter)  \
  template<>                                          \
  void VkDestroyer<type>::Destroy() {                 \
    if( nullptr != deleter ) {                        \
      deleter( Device, Object, nullptr );             \
    }                                                 \
  }

    void VkDestroyer<VkInstance>::Destroy() {
        if (nullptr != vkDestroyInstance) {
            vkDestroyInstance(Instance, nullptr);
        }
    }

    void VkDestroyer<VkDevice>::Destroy() {
        if (nullptr != vkDestroyDevice) {
            vkDestroyDevice(LogicalDevice, nullptr);
        }
    }

    void VkDestroyer<VkSurfaceKHR>::Destroy() {
        if (nullptr != vkDestroySurfaceKHR) {
            vkDestroySurfaceKHR(Instance, Object, nullptr);
        }
    }

    VK_DESTROYER_SPECIALIZATION(VkSemaphore, vkDestroySemaphore)
    // VK_DESTROYER_SPECIALIZATION( VkCommandBuffer, vkFreeCommandBuffers ) <- command buffers are freed along with the pool
    VK_DESTROYER_SPECIALIZATION(VkFence, vkDestroyFence)

    VK_DESTROYER_SPECIALIZATION(VkDeviceMemory, vkFreeMemory)

    VK_DESTROYER_SPECIALIZATION(VkBuffer, vkDestroyBuffer)

    VK_DESTROYER_SPECIALIZATION(VkImage, vkDestroyImage)

    VK_DESTROYER_SPECIALIZATION(VkEvent, vkDestroyEvent)

    VK_DESTROYER_SPECIALIZATION(VkQueryPool, vkDestroyQueryPool)

    VK_DESTROYER_SPECIALIZATION(VkBufferView, vkDestroyBufferView)

    VK_DESTROYER_SPECIALIZATION(VkImageView, vkDestroyImageView)

    VK_DESTROYER_SPECIALIZATION(VkShaderModule, vkDestroyShaderModule)

    VK_DESTROYER_SPECIALIZATION(VkPipelineCache, vkDestroyPipelineCache)

    VK_DESTROYER_SPECIALIZATION(VkPipelineLayout, vkDestroyPipelineLayout)

    VK_DESTROYER_SPECIALIZATION(VkRenderPass, vkDestroyRenderPass)

    VK_DESTROYER_SPECIALIZATION(VkPipeline, vkDestroyPipeline)

    VK_DESTROYER_SPECIALIZATION(VkDescriptorSetLayout, vkDestroyDescriptorSetLayout)

    VK_DESTROYER_SPECIALIZATION(VkSampler, vkDestroySampler)

    VK_DESTROYER_SPECIALIZATION(VkDescriptorPool, vkDestroyDescriptorPool)
    // VK_DESTROYER_SPECIALIZATION( VkDescriptorSet, vkFreeDescriptorSets ) <- descriptor sets are freed along with the pool
    VK_DESTROYER_SPECIALIZATION(VkFramebuffer, vkDestroyFramebuffer)

    VK_DESTROYER_SPECIALIZATION(VkCommandPool, vkDestroyCommandPool)

    VK_DESTROYER_SPECIALIZATION(VkSwapchainKHR, vkDestroySwapchainKHR)

}
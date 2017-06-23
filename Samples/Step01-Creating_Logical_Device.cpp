//
// Created by aicdg on 2017/6/23.
//

//
// 01-Creating_Logical_Device

#include "CookbookSampleFramework.h"
#include "All_Lib.h"

using namespace VKCookbook;

class Sample : public VulkanCookbookSampleBase {
  LIBRARY_TYPE            VulkanLibrary;
  VkDestroyer<VkInstance> Instance;
  VkDestroyer<VkDevice>   LogicalDevice;
  VkQueue                 GraphicsQueue;
  VkQueue                 ComputeQueue;

  virtual bool Initialize( WindowParameters  window_parameters ) override {
    if( !ConnectWithVulkanLoaderLibrary( VulkanLibrary ) ) {
      return false;
    }

    if( !LoadFunctionExportedFromVulkanLoaderLibrary( VulkanLibrary ) ) {
      return false;
    }

    if( !LoadGlobalLevelFunctions() ) {
      return false;
    }

    if( !CreateVulkanInstance( {}, "Vulkan Cookbook", *Instance ) ) {
      return false;
    }

    if( !LoadInstanceLevelFunctions( *Instance, {} ) ) {
      return false;
    }

    if( !CreateLogicalDeviceWithGeometryShadersAndGraphicsAndComputeQueues( *Instance, *LogicalDevice, GraphicsQueue, ComputeQueue ) ) {
      return false;
    }

    return true;
  }

  virtual bool Draw() override {
    return true;
  }

  virtual bool Resize() override {
    return true;
  }

  virtual void Deinitialize() override {
    if( LogicalDevice ) {
      WaitForAllSubmittedCommandsToBeFinished( *LogicalDevice );
    }
  }
};

VULKAN_COOKBOOK_SAMPLE_FRAMEWORK( "01 - Creating Logical Device", 50, 25, 1280, 800, Sample )

//
// CookbookSampleFramework

#ifndef COOKBOOK_SAMPLE_FRAMEWORK
#define COOKBOOK_SAMPLE_FRAMEWORK

#include <chrono>
#include "All_Lib.h"
#include "OS.h"
#include "Tools.h"

namespace VKCookbook {

  // Storage for mouse state parameters

  class MouseState {
  public:
    struct ButtonsState {
      bool IsPressed;
      bool WasClicked;
      bool WasRelease;
    } Buttons[2];
    struct Position {
      int X;
      int Y;
      struct Delta {
        int X;
        int Y;
      } Delta;
    } Position;
    struct WheelState {
      bool  WasMoved;
      float Distance;
    } Wheel;

      MouseState();
     ~MouseState();
  };

  // Class for simple time manipulations

  class TimerState {
  public:
    float   GetTime() const;
    float   GetDeltaTime() const;

    void    Update();

      TimerState();
     ~TimerState();

  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> Time;
    std::chrono::duration<float>                                DeltaTime;
  };

  // Simple containers for resources

  struct QueueParameters {
    VkQueue   Handle;
    uint32_t  FamilyIndex;
  };

  struct SwapchainParameters {
    VkDestroyer<VkSwapchainKHR>             Handle;
    VkFormat                                Format;
    VkExtent2D                              Size;
    std::vector<VkImage>                    Images;
    std::vector<VkDestroyer<VkImageView>>   ImageViews;
    std::vector<VkImageView>                ImageViewsRaw;
  };

  // Base class for implementing Vulkan Cookbook code samples

  class VulkanCookbookSampleBase {
  public:
              VulkanCookbookSampleBase();
    virtual  ~VulkanCookbookSampleBase();

    virtual bool  Initialize( WindowParameters window_parameters ) = 0;
    virtual bool  Draw() = 0;
    virtual bool  Resize() = 0;
    virtual void  Deinitialize() = 0;
    virtual void  MouseClick( size_t button_index, bool state ) final;
    virtual void  MouseMove( int x, int y ) final;
    virtual void  MouseWheel( float distance ) final;
    virtual void  MouseReset() final;
    virtual void  UpdateTime() final;
    virtual bool  IsReady() final;

  protected:
    virtual void  OnMouseEvent();

    LIBRARY_TYPE  VulkanLibrary;
    bool          Ready;
    MouseState    MouseState;
    TimerState    TimerState;
  };

  // Base class for code samples with default instance, device and swapchain creation

  class VulkanCookbookSample : public VulkanCookbookSampleBase {
  public:
    VkDestroyer<VkInstance>                   Instance;
    VkPhysicalDevice                          PhysicalDevice;
    VkDestroyer<VkDevice>                     LogicalDevice;
    VkDestroyer<VkSurfaceKHR>                 PresentationSurface;
    QueueParameters                           GraphicsQueue;
    QueueParameters                           ComputeQueue;
    QueueParameters                           PresentQueue;
    SwapchainParameters                       Swapchain;
    VkDestroyer<VkCommandPool>                CommandPool;
    std::vector<VkDestroyer<VkImage>>         DepthImages;
    std::vector<VkDestroyer<VkDeviceMemory>>  DepthImagesMemory;
    std::vector<FrameResources>               FrameResources;
    static uint32_t const                     FramesCount = 3;
    static VkFormat const                     DepthFormat = VK_FORMAT_D16_UNORM;

    virtual bool  InitializeVulkan( WindowParameters           window_parameters,
                                    VkPhysicalDeviceFeatures * desired_device_features = nullptr,
                                    VkImageUsageFlags          swapchain_image_usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                                    bool                       use_depth = true,
                                    VkImageUsageFlags          depth_attachment_usage = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT ) final;
    virtual bool  CreateSwapchain( VkImageUsageFlags swapchain_image_usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                                   bool              use_depth = true,
                                   VkImageUsageFlags depth_attachment_usage = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT ) final;
    virtual void  Deinitialize() final;
  };

  // Application starting point implementation

#define VULKAN_COOKBOOK_SAMPLE_FRAMEWORK( title, x, y, width, height, sample_type )   \
                                                                                      \
  int main() {                                                                        \
    sample_type sample;                                                               \
    WindowFramework window( "Vulkan Cookbook #" title, x, y, width, height, sample ); \
                                                                                      \
    window.Render();                                                                  \
                                                                                      \
    return 0;                                                                         \
  }

} // namespace VulkanCookbook

#endif // COOKBOOK_SAMPLE_FRAMEWORK
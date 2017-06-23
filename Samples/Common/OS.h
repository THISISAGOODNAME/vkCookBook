//
// OS

#ifndef OS
#define OS

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Common.h"

namespace VKCookbook {

  class VulkanCookbookSampleBase;

  // Window managemenet class

  class WindowFramework {
  public:
             WindowFramework( const char               * window_title,
                              int                        x,
                              int                        y,
                              int                        width,
                              int                        height,
                              VulkanCookbookSampleBase & sample );
    virtual ~WindowFramework();

    virtual void Render() final;

  private:
    WindowParameters           WindowParameters;
    VulkanCookbookSampleBase & Sample;
    bool                       Created;
  };

} // namespace VulkanCookbook

#endif // OS
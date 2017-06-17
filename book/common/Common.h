//
// Created by aicdg on 2017/6/14.
//

//
// Common

#ifndef VKCOOKBOOK_COMMON_H
#define VKCOOKBOOK_COMMON_H


#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <thread>
#include <functional>
#include "VulkanDestroyer.h"

namespace VKCookbook {

    // Vulkan library type
#ifdef _WIN32
#define LIBRARY_TYPE HMODULE
#endif

    // OS-specific parameters
    struct WindowParameters {
#ifdef VK_USE_PLATFORM_WIN32_KHR

        HINSTANCE          HInstance;
        HWND               HWnd;

#elif defined VK_USE_PLATFORM_XLIB_KHR

        Display          * Dpy;
        Window             Window;

#elif defined VK_USE_PLATFORM_XCB_KHR

        xcb_connection_t * Connection;
        xcb_window_t       Window;

#endif
    };

    // Extension availability check
    bool IsExtensionSupported( std::vector<VkExtensionProperties> const & available_extensions,
                               char const * const                         extension );

};


#endif //VKCOOKBOOK_COMMON_H

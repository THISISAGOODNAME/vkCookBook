//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  02 Creating a presentation surface

#include "S02_Creating_a_presentation_surface.h"

namespace VKCookbook {

    bool CreatePresentationSurface( VkInstance         instance,
                                    WindowParameters   window_parameters,
                                    VkSurfaceKHR     & presentation_surface ) {
        VkResult result;

#ifdef VK_USE_PLATFORM_WIN32_KHR

        VkWin32SurfaceCreateInfoKHR surface_create_info = {
            VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,  // VkStructureType                 sType
            nullptr,                                          // const void                    * pNext
            0,                                                // VkWin32SurfaceCreateFlagsKHR    flags
            window_parameters.HInstance,                      // HINSTANCE                       hinstance
            window_parameters.HWnd                            // HWND                            hwnd
        };

        result = vkCreateWin32SurfaceKHR( instance, &surface_create_info, nullptr, &presentation_surface );

#elif defined VK_USE_PLATFORM_XLIB_KHR

        VkXlibSurfaceCreateInfoKHR surface_create_info = {
            VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR,   // VkStructureType                 sType
            nullptr,                                          // const void                    * pNext
            0,                                                // VkXlibSurfaceCreateFlagsKHR     flags
            window_parameters.Dpy,                            // Display                       * dpy
            window_parameters.Window                          // Window                          window
        };

        result = vkCreateXlibSurfaceKHR( instance, &surface_create_info, nullptr, &presentation_surface );

#elif defined VK_USE_PLATFORM_XCB_KHR

        VkXcbSurfaceCreateInfoKHR surface_create_info = {
            VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR,    // VkStructureType                 sType
            nullptr,                                          // const void                    * pNext
            0,                                                // VkXcbSurfaceCreateFlagsKHR      flags
            window_parameters.Connection,                     // xcb_connection_t              * connection
            window_parameters.Window                          // xcb_window_t                    window
        };

        result = vkCreateXcbSurfaceKHR( instance, &surface_create_info, nullptr, &presentation_surface );

#endif

        if ( (VK_SUCCESS != result) || (VK_NULL_HANDLE == presentation_surface) ) {
            std::cout << "Could not create presentation surface." << std::endl;
            return false;
        }
        return true;
    }

}
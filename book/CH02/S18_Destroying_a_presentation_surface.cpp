//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  18 Destroying a presentation surface

#include "S18_Destroying_a_presentation_surface.h"

namespace VKCookbook {

    void DestroyPresentationSurface( VkInstance     instance,
                                     VkSurfaceKHR & presentation_surface ) {
        if( presentation_surface ) {
            vkDestroySurfaceKHR( instance, presentation_surface, nullptr );
            presentation_surface = VK_NULL_HANDLE;
        }
    }

}
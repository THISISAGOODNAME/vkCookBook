//
// Created by aicdg on 2017/6/19.
//

//
// Chapter: 02 Image Presentation
// Recipe:  18 Destroying a presentation surface

#ifndef VKCOOKBOOK_S18_DESTROYING_A_PRESENTATION_SURFACE_H
#define VKCOOKBOOK_S18_DESTROYING_A_PRESENTATION_SURFACE_H

#include "Common.h"

namespace VKCookbook {

    void DestroyPresentationSurface( VkInstance     instance,
                                     VkSurfaceKHR & presentation_surface );

};


#endif //VKCOOKBOOK_S18_DESTROYING_A_PRESENTATION_SURFACE_H

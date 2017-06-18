//
// Created by aicdg on 2017/6/18.
//

//
// Chapter: 02 Image Presentation
// Recipe:  02 Creating a presentation surface

#ifndef VKCOOKBOOK_S02_CREATING_A_PRESENTATION_SURFACE_H
#define VKCOOKBOOK_S02_CREATING_A_PRESENTATION_SURFACE_H

#include "Common.h"

namespace VKCookbook {

    bool CreatePresentationSurface( VkInstance         instance,
                                    WindowParameters   window_parameters,
                                    VkSurfaceKHR     & presentation_surface );

};


#endif //VKCOOKBOOK_S02_CREATING_A_PRESENTATION_SURFACE_H

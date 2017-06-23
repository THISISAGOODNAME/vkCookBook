//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  04 Preparing a perspective projection matrix

#ifndef VKCOOKBOOK_S04_PREPARING_A_PERSPECTIVE_PROJECTION_MATRIX_H
#define VKCOOKBOOK_S04_PREPARING_A_PERSPECTIVE_PROJECTION_MATRIX_H

#include "Tools.h"

namespace VKCookbook {

    Matrix4x4 PreparePerspectiveProjectionMatrix( float aspect_ratio,
                                                  float field_of_view,
                                                  float near_plane,
                                                  float far_plane );

};


#endif //VKCOOKBOOK_S04_PREPARING_A_PERSPECTIVE_PROJECTION_MATRIX_H

//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  05 Preparing an orthographic projection matrix

#ifndef VKCOOKBOOK_S05_PREPARING_AN_ORTHOGRAPHIC_PROJECTION_MATRIX_H
#define VKCOOKBOOK_S05_PREPARING_AN_ORTHOGRAPHIC_PROJECTION_MATRIX_H

#include "Tools.h"

namespace VKCookbook {

    Matrix4x4 PrepareOrthographicProjectionMatrix( float left_plane,
                                                   float right_plane,
                                                   float bottom_plane,
                                                   float top_plane,
                                                   float near_plane,
                                                   float far_plane );

};


#endif //VKCOOKBOOK_S05_PREPARING_AN_ORTHOGRAPHIC_PROJECTION_MATRIX_H

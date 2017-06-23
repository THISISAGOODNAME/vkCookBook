//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  02 Preparing a rotation matrix

#ifndef VKCOOKBOOK_S02_PREPARING_A_ROTATION_MATRIX_H
#define VKCOOKBOOK_S02_PREPARING_A_ROTATION_MATRIX_H

#include "Tools.h"

namespace VKCookbook {

    Matrix4x4 PrepareRotationMatrix( float           angle,
                                     Vector3 const & axis,
                                     float           normalize_axis = false );

};


#endif //VKCOOKBOOK_S02_PREPARING_A_ROTATION_MATRIX_H

//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  03 Preparing a scaling matrix

#include "S03_Preparing_a_scaling_matrix.h"

namespace VKCookbook {

    Matrix4x4 PrepareScalingMatrix( float x,
                                    float y,
                                    float z ){
        Matrix4x4 scaling_matrix = {
                   x, 0.0f, 0.0f, 0.0f,
                0.0f,    y, 0.0f, 0.0f,
                0.0f, 0.0f,    z, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f
        };
        return scaling_matrix;
    }

}
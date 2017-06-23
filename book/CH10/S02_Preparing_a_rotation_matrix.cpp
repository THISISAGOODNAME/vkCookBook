//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  02 Preparing a rotation matrix

#include "S02_Preparing_a_rotation_matrix.h"

namespace VKCookbook {

    Matrix4x4 PrepareRotationMatrix( float           angle,
                                     Vector3 const & axis,
                                     float           normalize_axis ){
        float x;
        float y;
        float z;

        if( normalize_axis ) {
            Vector3 normalized = Normalize( axis );
            x = normalized[0];
            y = normalized[1];
            z = normalized[2];
        } else {
            x = axis[0];
            y = axis[1];
            z = axis[2];
        }

        const float c = cos( Deg2Rad( angle ) );
        const float _1_c = 1.0f - c;
        const float s = sin( Deg2Rad( angle ) );

        Matrix4x4 rotation_matrix = {
                x * x * _1_c + c,
                y * x * _1_c - z * s,
                z * x * _1_c + y * s,
                0.0f,

                x * y * _1_c + z * s,
                y * y * _1_c + c,
                z * y * _1_c - x * s,
                0.0f,

                x * z * _1_c - y * s,
                y * z * _1_c + x * s,
                z * z * _1_c + c,
                0.0f,

                0.0f,
                0.0f,
                0.0f,
                1.0f
        };
        return rotation_matrix;
    }

}
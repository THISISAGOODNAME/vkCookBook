//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  01 Preparing a translation matrix

#include "S01_reparing_a_translation_matrix.h"

namespace VKCookbook {

    Matrix4x4 PrepareTranslationMatrix( float x,
                                        float y,
                                        float z ){
        Matrix4x4 translation_matrix = {
                1.0f, 0.0f, 0.0f, 0.0f,
                0.0f, 1.0f, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                x,    y,    z, 1.0f
        };
        return translation_matrix;
    }

}
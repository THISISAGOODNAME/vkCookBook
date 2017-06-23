//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  07 Loading a 3D model from an OBJ file

#ifndef VKCOOKBOOK_S07_LOADING_A_3D_MODEL_FROM_AN_OBJ_FILE_H
#define VKCOOKBOOK_S07_LOADING_A_3D_MODEL_FROM_AN_OBJ_FILE_H

#include "Tools.h"

namespace VKCookbook {

    struct Mesh {
        std::vector<float>  Data;

        struct Part {
            uint32_t  VertexOffset;
            uint32_t  VertexCount;
        };

        std::vector<Part>   Parts;
    };

    bool Load3DModelFromObjFile( char const * filename,
                                 bool         load_normals,
                                 bool         load_texcoords,
                                 bool         generate_tangent_space_vectors,
                                 bool         unify,
                                 Mesh       & mesh,
                                 uint32_t   * vertex_stride = nullptr );

};


#endif //VKCOOKBOOK_S07_LOADING_A_3D_MODEL_FROM_AN_OBJ_FILE_H

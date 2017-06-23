//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  06 Loading texture data from a file

#ifndef VKCOOKBOOK_S06_LOADING_TEXTURE_DATA_FROM_A_FILE_H
#define VKCOOKBOOK_S06_LOADING_TEXTURE_DATA_FROM_A_FILE_H

#include "Tools.h"

namespace VKCookbook {

    bool LoadTextureDataFromFile( char const                 * filename,
                                  int                          num_requested_components,
                                  std::vector<unsigned char> & image_data,
                                  int                        * image_width = nullptr,
                                  int                        * image_height = nullptr,
                                  int                        * image_num_components = nullptr,
                                  int                        * image_data_size = nullptr );

};


#endif //VKCOOKBOOK_S06_LOADING_TEXTURE_DATA_FROM_A_FILE_H

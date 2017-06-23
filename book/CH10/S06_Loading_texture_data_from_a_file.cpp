//
// Created by aicdg on 2017/6/23.
//

//
// Chapter: 10 Helper Recipes
// Recipe:  06 Loading texture data from a file

#include "S06_Loading_texture_data_from_a_file.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace VKCookbook {

    bool LoadTextureDataFromFile( char const                 * filename,
                                  int                          num_requested_components,
                                  std::vector<unsigned char> & image_data,
                                  int                        * image_width,
                                  int                        * image_height,
                                  int                        * image_num_components,
                                  int                        * image_data_size ){
        int width = 0;
        int height = 0;
        int num_components = 0;
        std::unique_ptr<unsigned char, void(*)(void*)> stbi_data( stbi_load( filename, &width, &height, &num_components, num_requested_components ), stbi_image_free );

        if( (!stbi_data) ||
            (0 >= width) ||
            (0 >= height) ||
            (0 >= num_components) ) {
            std::cout << "Could not read image!" << std::endl;
            return false;
        }

        int data_size = width * height * (0 < num_requested_components ? num_requested_components : num_components);
        if( image_data_size ) {
            *image_data_size = data_size;
        }
        if( image_width ) {
            *image_width = width;
        }
        if( image_height ) {
            *image_height = height;
        }
        if( image_num_components ) {
            *image_num_components = num_components;
        }

        image_data.resize( data_size );
        std::memcpy( image_data.data(), stbi_data.get(), data_size );
        return true;
    }

}
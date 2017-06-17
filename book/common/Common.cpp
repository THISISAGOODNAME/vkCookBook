//
// Created by aicdg on 2017/6/14.
//
//
// Common
// Common

#include "Common.h"

namespace VKCookbook {

    bool IsExtensionSupported( std::vector<VkExtensionProperties> const & available_extensions,
                               char const * const                         extension ) {
        for( auto & available_extension : available_extensions ) {
            if( strstr( available_extension.extensionName, extension ) ) {
                return true;
            }
        }
        return false;
    }

}
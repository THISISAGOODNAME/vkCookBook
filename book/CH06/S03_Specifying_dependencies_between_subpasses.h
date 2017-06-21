//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  03 Specifying dependencies between subpasses

#ifndef VKCOOKBOOK_S03_SPECIFYING_DEPENDENCIES_BETWEEN_SUBPASSES_H
#define VKCOOKBOOK_S03_SPECIFYING_DEPENDENCIES_BETWEEN_SUBPASSES_H

#include "Common.h"

namespace VKCookbook {

    void SpecifyDependenciesBetweenSubpasses( std::vector<VkSubpassDependency> const & subpasses_dependencies );

};


#endif //VKCOOKBOOK_S03_SPECIFYING_DEPENDENCIES_BETWEEN_SUBPASSES_H

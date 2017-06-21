//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  03 Specifying dependencies between subpasses

#include "S03_Specifying_dependencies_between_subpasses.h"

namespace VKCookbook {

    void SpecifyDependenciesBetweenSubpasses( std::vector<VkSubpassDependency> const & subpasses_dependencies ) {
        // typedef struct VkSubpassDependency {
        //   uint32_t                srcSubpass;
        //   uint32_t                dstSubpass;
        //   VkPipelineStageFlags    srcStageMask;
        //   VkPipelineStageFlags    dstStageMask;
        //   VkAccessFlags           srcAccessMask;
        //   VkAccessFlags           dstAccessMask;
        //   VkDependencyFlags       dependencyFlags;
        // } VkSubpassDependency;
    }

}
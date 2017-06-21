//
// Created by aicdg on 2017/6/21.
//

//
// Chapter: 06 Render Passes and Framebuffers
// Recipe:  06 Preparing a render pass for geometry rendering and postprocess subpasses

#ifndef VKCOOKBOOK_S06_PREPARING_A_RENDER_PASS_FOR_GEOMETRY_RENDERING_AND_POSTPROCESS_SUBPASSES_H
#define VKCOOKBOOK_S06_PREPARING_A_RENDER_PASS_FOR_GEOMETRY_RENDERING_AND_POSTPROCESS_SUBPASSES_H

#include "Common.h"

namespace VKCookbook {

    bool PrepareRenderPassForGeometryRenderingAndPostprocessSubpasses( VkDevice     logical_device,
                                                                       VkRenderPass render_pass );

};


#endif //VKCOOKBOOK_S06_PREPARING_A_RENDER_PASS_FOR_GEOMETRY_RENDERING_AND_POSTPROCESS_SUBPASSES_H

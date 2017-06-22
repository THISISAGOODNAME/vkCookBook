//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  02 Specifying pipeline shader stages

#ifndef VKCOOKBOOK_S02_SPECIFYING_PIPELINE_SHADER_STAGES_H
#define VKCOOKBOOK_S02_SPECIFYING_PIPELINE_SHADER_STAGES_H

#include "Common.h"

namespace VKCookbook {

    struct ShaderStageParameters {
        VkShaderStageFlagBits        ShaderStage;
        VkShaderModule               ShaderModule;
        char const                 * EntryPointName;
        VkSpecializationInfo const * SpecializationInfo;
    };

    void SpecifyPipelineShaderStages( std::vector<ShaderStageParameters> const     & shader_stage_params,
                                      std::vector<VkPipelineShaderStageCreateInfo> & shader_stage_create_infos );

};


#endif //VKCOOKBOOK_S02_SPECIFYING_PIPELINE_SHADER_STAGES_H

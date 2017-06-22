//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  02 Specifying pipeline shader stages

#include "S02_Specifying_pipeline_shader_stages.h"

namespace VKCookbook {

    void SpecifyPipelineShaderStages( std::vector<ShaderStageParameters> const     & shader_stage_params,
                                      std::vector<VkPipelineShaderStageCreateInfo> & shader_stage_create_infos ) {
        shader_stage_create_infos.clear();
        for( auto & shader_stage : shader_stage_params ) {
            shader_stage_create_infos.push_back( {
                                                         VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,  // VkStructureType                    sType
                                                         nullptr,                                              // const void                       * pNext
                                                         0,                                                    // VkPipelineShaderStageCreateFlags   flags
                                                         shader_stage.ShaderStage,                             // VkShaderStageFlagBits              stage
                                                         shader_stage.ShaderModule,                            // VkShaderModule                     module
                                                         shader_stage.EntryPointName,                          // const char                       * pName
                                                         shader_stage.SpecializationInfo                       // const VkSpecializationInfo       * pSpecializationInfo
                                                 } );
        }
    }

}
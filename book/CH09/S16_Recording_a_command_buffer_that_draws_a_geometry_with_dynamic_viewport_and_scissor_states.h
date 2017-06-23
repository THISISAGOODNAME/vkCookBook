//
// Created by yangyanjun on 2017/6/23.
//

//
// Chapter: 09 Command Recording and Drawing
// Recipe:  16 Recording a command buffer that draws a geometry with dynamic viewport and scissor states

#ifndef VKCOOKBOOK_S16_RECORDING_A_COMMAND_BUFFER_THAT_DRAWS_A_GEOMETRY_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_STATES_H
#define VKCOOKBOOK_S16_RECORDING_A_COMMAND_BUFFER_THAT_DRAWS_A_GEOMETRY_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_STATES_H

#include "../CH09/S04_Binding_vertex_buffers.h"
#include "../CH10/S07_Loading_a_3D_model_from_an_OBJ_file.h"

namespace VKCookbook {

    bool RecordCommandBufferThatDrawsGeometryWithDynamicViewportAndScissorStates( VkCommandBuffer                             command_buffer,
                                                                                  VkImage                                     swapchain_image,
                                                                                  uint32_t                                    present_queue_family_index,
                                                                                  uint32_t                                    graphics_queue_family_index,
                                                                                  VkRenderPass                                render_pass,
                                                                                  VkFramebuffer                               framebuffer,
                                                                                  VkExtent2D                                  framebuffer_size,
                                                                                  std::vector<VkClearValue> const &           clear_values,
                                                                                  VkPipeline                                  graphics_pipeline,
                                                                                  uint32_t                                    first_vertex_buffer_binding,
                                                                                  std::vector<VertexBufferParameters> const & vertex_buffers_parameters,
                                                                                  VkPipelineLayout                            pipeline_layout,
                                                                                  std::vector<VkDescriptorSet> const &        descriptor_sets,
                                                                                  uint32_t                                    index_for_first_descriptor_set,
                                                                                  Mesh const &                                geometry,
                                                                                  uint32_t                                    instance_count,
                                                                                  uint32_t                                    first_instance );

};


#endif //VKCOOKBOOK_S16_RECORDING_A_COMMAND_BUFFER_THAT_DRAWS_A_GEOMETRY_WITH_DYNAMIC_VIEWPORT_AND_SCISSOR_STATES_H

//
// Created by aicdg on 2017/6/22.
//

//
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  22 Creating multiple graphics pipelines on multiple threads

#include "Tools.h"
#include "S14_Creating_a_pipeline_cache_object.h"
#include "S15_Retrieving_data_from_a_pipeline_cache.h"
#include "S16_Merging_multiple_pipeline_cache_objects.h"
#include "S17_Creating_graphics_pipelines.h"
#include "S22_Creating_multiple_graphics_pipelines_on_multiple_threads.h"

namespace VKCookbook {

    bool CreateMultipleGraphicsPipelinesOnMultipleThreads( VkDevice                                                       logical_device,
                                                           std::string const                                            & pipeline_cache_filename,
                                                           std::vector<std::vector<VkGraphicsPipelineCreateInfo>> const & graphics_pipelines_create_infos,
                                                           std::vector<std::vector<VkPipeline>>                         & graphics_pipelines ){
// Load cache from file (if available)
        std::vector<unsigned char> cache_data;
        GetBinaryFileContents( pipeline_cache_filename, cache_data );

        // Create cache for each thread, initialize its contents with data loaded from file
        std::vector<VkDestroyer<VkPipelineCache>> pipeline_caches( graphics_pipelines_create_infos.size() );
        for( size_t i = 0; i < graphics_pipelines_create_infos.size(); ++i ) {
            pipeline_caches[i] = VkDestroyer< VkPipelineCache >( logical_device );
            if( !CreatePipelineCacheObject( logical_device, cache_data, *pipeline_caches[i] ) ) {
                return false;
            }
        }

        // Create multiple threads, where each thread creates multiple pipelines using its own cache
        std::vector<std::thread> threads( graphics_pipelines_create_infos.size() );
        for( size_t i = 0; i < graphics_pipelines_create_infos.size(); ++i ) {
            graphics_pipelines[i].resize( graphics_pipelines_create_infos[i].size() );
            threads[i] = std::thread::thread( CreateGraphicsPipelines, logical_device, graphics_pipelines_create_infos[i], *pipeline_caches[i], graphics_pipelines[i] );
        }

        // Wait for all threads to finish
        for( size_t i = 0; i < graphics_pipelines_create_infos.size(); ++i ) {
            threads[i].join();
        }

        // Merge all the caches into one, retrieve its contents and store them in the file
        VkPipelineCache target_cache = *pipeline_caches.back();
        std::vector<VkPipelineCache> source_caches( pipeline_caches.size() - 1);
        for( size_t i = 0; i < pipeline_caches.size() - 1; ++i ) {
            source_caches[i] = *pipeline_caches[i];
        }

        if( !MergeMultiplePipelineCacheObjects( logical_device, target_cache, source_caches ) ) {
            return false;
        }

        if( !RetrieveDataFromPipelineCache( logical_device, target_cache, cache_data ) ) {
            return false;
        }

        //if( !SaveBinaryFile( pipeline_cache_filename, cache_data ) ) {
        //  return false;
        //}

        return true;
    }

}
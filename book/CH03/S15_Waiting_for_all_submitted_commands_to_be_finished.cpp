//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  15 Waiting for all submitted commands to be finished

#include "S15_Waiting_for_all_submitted_commands_to_be_finished.h"

namespace VKCookbook {

    bool WaitForAllSubmittedCommandsToBeFinished( VkDevice logical_device ) {
        VkResult result = vkDeviceWaitIdle( logical_device );
        if( VK_SUCCESS != result ) {
            std::cout << "Waiting on a device failed." << std::endl;
            return false;
        }
        return true;
    }

}
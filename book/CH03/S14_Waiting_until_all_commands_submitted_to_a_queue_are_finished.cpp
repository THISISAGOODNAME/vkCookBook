//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  14 Waiting until all commands submitted to a queue are finished

#include "S14_Waiting_until_all_commands_submitted_to_a_queue_are_finished.h"

namespace VKCookbook {

    bool WaitUntilAllCommandsSubmittedToQueueAreFinished( VkQueue queue ) {
        VkResult result = vkQueueWaitIdle( queue );
        if( VK_SUCCESS != result ) {
            std::cout << "Waiting for all operations submitted to queue failed." << std::endl;
            return false;
        }
        return true;
    }

}

//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  15 Waiting for all submitted commands to be finished

#ifndef VKCOOKBOOK_S15_WAITING_FOR_ALL_SUBMITTED_COMMANDS_TO_BE_FINISHED_H
#define VKCOOKBOOK_S15_WAITING_FOR_ALL_SUBMITTED_COMMANDS_TO_BE_FINISHED_H

#include "Common.h"

namespace VKCookbook {

    bool WaitForAllSubmittedCommandsToBeFinished( VkDevice logical_device );

};


#endif //VKCOOKBOOK_S15_WAITING_FOR_ALL_SUBMITTED_COMMANDS_TO_BE_FINISHED_H

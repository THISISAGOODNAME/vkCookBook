//
// Created by aicdg on 2017/6/20.
//

//
// Chapter: 03 Command Buffers and Synchronization
// Recipe:  14 Waiting until all commands submitted to a queue are finished

#ifndef VKCOOKBOOK_S14_WAITING_UNTIL_ALL_COMMANDS_SUBMITTED_TO_A_QUEUE_ARE_FINISHED_H
#define VKCOOKBOOK_S14_WAITING_UNTIL_ALL_COMMANDS_SUBMITTED_TO_A_QUEUE_ARE_FINISHED_H

#include "Common.h"

namespace VKCookbook {

    bool WaitUntilAllCommandsSubmittedToQueueAreFinished( VkQueue queue );

};


#endif //VKCOOKBOOK_S14_WAITING_UNTIL_ALL_COMMANDS_SUBMITTED_TO_A_QUEUE_ARE_FINISHED_H

#if defined(_WIN32) || defined(_WIN64)

#include "win.h"


static void CALLBACK run_async(long unsigned int ai_ptr) {

    AwaitInfo *ai = (AwaitInfo *)ai_ptr;
    run_awaitable(ai);
}


void queue_awaitable(AwaitInfo *ai) {

    QueueUserAPC(&run_async, GetCurrentThread(), (long unsigned int)ai);
}

#endif
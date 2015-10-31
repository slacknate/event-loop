#if defined(_WIN32) || defined(_WIN64)

#include "win.h"


static void CALLBACK run_async(long unsigned int ai_ptr) {

    await_info *ai = (await_info *)ai_ptr;
    ai->blap(NULL);
}


void queue_awaitable(await_info *ai) {

    QueueUserAPC(&run_async, GetCurrentThread(), (long unsigned int)ai);
}

#endif
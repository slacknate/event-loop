#include "loop.h"

#if defined(_WIN32) || defined(_WIN64)
// Windows MinGW
#include "win.h"
#endif

#ifdef __GNUC__
// Linux GCC
#endif

#ifdef __APPLE__
// Mac OSX
#endif

void schedule(Awaitable func) {

    AwaitInfo *ai = create_await_info(func, NULL);
    queue_awaitable(ai);

    // FIXME: how the fuck do I free the await info struct for this case?
}


void *await(Awaitable func) {

    Event *event = create_event();
    AwaitInfo *ai = create_await_info(func, event);

    queue_awaitable(ai);
    wait_for_event(ai->event);

    destroy_event(ai->event);
    destroy_await_info(ai);

    return ai->result;
}

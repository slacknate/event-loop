#include "loop.h"


void run_awaitable(await_info *ai) {

    ai->result = ai->func(NULL);

    if(ai->event != NULL)
        signal_event(ai->event);
}


await_info *create_await_info(Awaitable func, Event *event) {

    await_info *ai = (await_info *)malloc(sizeof(await_info));

    ai->func = func;
    ai->event = event;
    ai->blap = &run_awaitable;

    return ai;
}


void destroy_await_info(await_info *ai) {

    ai->func = NULL;
    ai->blap = NULL;
    ai->event = NULL;

    free(ai);
}


void schedule(Awaitable func) {

    await_info *ai = create_await_info(func, NULL);
    queue_awaitable(ai);

    // FIXME: how the fuck do I free the await info struct for this case?
}


void *await(Awaitable func) {

    Event *event = create_event();
    await_info *ai = create_await_info(func, event);

    queue_awaitable(ai);
    wait_for_event(ai->event);

    destroy_event(ai->event);
    destroy_await_info(ai);

    return ai->result;
}

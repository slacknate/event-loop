#include "awaitable.h"


await_info *create_await_info(Awaitable func, Event *event) {

    await_info *ai = (await_info *)malloc(sizeof(await_info));

    ai->func = func;
    ai->event = event;

    return ai;
}


void destroy_await_info(await_info *ai) {

    ai->func = NULL;
    ai->event = NULL;

    free(ai);
}


void run_awaitable(await_info *ai) {

    ai->result = ai->func(NULL);

    if(ai->event != NULL)
        signal_event(ai->event);
}
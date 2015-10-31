#include "awaitable.h"


AwaitInfo *create_await_info(Awaitable func, Event *event) {

    AwaitInfo *ai = (AwaitInfo *)malloc(sizeof(AwaitInfo));

    ai->func = func;
    ai->event = event;

    return ai;
}


void destroy_await_info(AwaitInfo *ai) {

    ai->func = NULL;
    ai->event = NULL;

    free(ai);
}


void run_awaitable(AwaitInfo *ai) {

    ai->result = ai->func(NULL);

    if(ai->event != NULL)
        signal_event(ai->event);
}
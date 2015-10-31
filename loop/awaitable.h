#ifndef AWAITABLE_H
#define AWAITABLE_H

#include "../event/event.h"

typedef void* (*Awaitable)(void *);

typedef struct {

    Event *event;
    Awaitable func;
    void *result;

} AwaitInfo;

AwaitInfo *create_await_info(Awaitable func, Event *event);
void destroy_await_info(AwaitInfo *ai);

void run_awaitable(AwaitInfo *ai);

#endif //AWAITABLE_H

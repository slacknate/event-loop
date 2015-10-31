#ifndef AWAITABLE_H
#define AWAITABLE_H

#include "../event/event.h"

typedef void* (*Awaitable)(void *);

typedef struct _await_info {

    Event *event;
    Awaitable func;
    void *result;

} await_info;

await_info *create_await_info(Awaitable func, Event *event);
void destroy_await_info(await_info *ai);

void run_awaitable(await_info *ai);

#endif //AWAITABLE_H

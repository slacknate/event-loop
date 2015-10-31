#ifndef AWAITABLE_H
#define AWAITABLE_H

#include "../event/event.h"

typedef struct _await_info await_info;

typedef void* (*Awaitable)(void *);
typedef void (*Blap)(await_info *);

typedef struct _await_info {

    Event *event;
    Awaitable func;
    Blap blap;
    void *result;

} await_info;

#endif //AWAITABLE_H

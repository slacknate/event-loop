#ifndef LOOP_H
#define LOOP_H

#include "awaitable.h"

void schedule(Awaitable func);
void *await(Awaitable func);

#endif //LOOP_H

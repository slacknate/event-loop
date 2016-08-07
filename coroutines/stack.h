#ifndef STACK_H
#define STACK_H

#include <inttypes.h>

uint8_t *save_stack();
void stack_restore(uint8_t *ptr);

#endif

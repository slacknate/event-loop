#include <stdio.h>
#include "loop/loop.h"


void *foo(void *_) {

    SleepEx(2500, 1);
    printf("O'hallo!\n");
    return NULL;
}


void *bar(void *_) {

    SleepEx(3000, 1);
    printf("Howdy!\n");
    return NULL;
}


int main(int argc, char *argv[]) {

    schedule(&foo);
    await(&bar);
    return 0;
}
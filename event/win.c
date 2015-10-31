#if defined(_WIN32) || defined(_WIN64)

#include "win.h"

Event *create_event() {

    Event *event = (Event *)malloc(sizeof(Event));
    event->descriptor = CreateEvent(NULL, 1, 0, NULL);
    return event;
}


void destroy_event(Event *event) {

    CloseHandle(event->descriptor);
    free(event);
}


void signal_event(Event *event) {

    SetEvent(event->descriptor);
}


void wait_for_event(Event *event) {

    WaitForSingleObjectEx(event->descriptor, INFINITE, 1);
}

#endif
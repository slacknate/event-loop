#ifndef EVENT_WIN_H
#define EVENT_WIN_H

#include <windows.h>

typedef struct _Event {

    HANDLE descriptor;

} Event;

Event *create_event();
void destroy_event(Event *ev);

void signal_event(Event *ev);
void wait_for_event(Event *ev);

#endif //EVENT_WIN_H

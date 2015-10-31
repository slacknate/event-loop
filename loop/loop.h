#ifndef LOOP_H
#define LOOP_H

#if defined(_WIN32) || defined(_WIN64)
// Windows MinGW
#include "win.h"
#endif

#ifdef __GNUC__
// Linux GCC
#endif

#ifdef __APPLE__
// Mac OSX
#endif

#endif //LOOP_H

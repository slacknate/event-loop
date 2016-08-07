cmake_minimum_required(VERSION 3.3)
project(event_loop C ASM)

set(CMAKE_ASM_COMPILE_OBJECT "llc -filetype=obj <SOURCE> -o <OBJECT>")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES

    main.c

    coroutines/stack.asm

    loop/loop.c loop/loop.h
    loop/awaitable.c loop/awaitable.h
    loop/win.c loop/win.h

    event/event.h
    event/win.c event/win.h
)

add_executable(event_loop ${SOURCE_FILES})

target_link_libraries(event_loop pthread)
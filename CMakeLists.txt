cmake_minimum_required(VERSION 3.3)
project(event_loop, C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

set(SOURCE_FILES main.c loop/loop.c event/win.c event/win.h event/event.h loop/win.c loop/win.h loop/loop.h loop/awaitable.h)
add_executable(event_loop ${SOURCE_FILES})

target_link_libraries(event_loop pthread)
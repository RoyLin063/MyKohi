#pragma once

#include "defines.h"

typedef struct platform_state
{
    void* internal_state;
}platform_state;

b8 platform_startup(
    platform_state* plat_state,
    char const* application_name,
    i32 x,
    i32 y,
    i32 width,
    i32 height
);

// We don't want to exposure platform interfaces.
void platform_shutdown(platform_state* plat_state);

// Application calls this once every single loop.
b8 platform_pump_messages(platform_state* plat_state);

// Memmory allocation and deallocation is also
// platform related.

KAPI void* platform_allocate(u64 size, b8 aligned);
KAPI void platfrom_free(void* block, b8 aligned);
void platform_zero_memory(void* block, u64 size);
void platform_copy_memory(void* dest, void const* source, u64 size);
void platform_set_memory(void* block, i32 value, u64 size);

// Write colored text to the command prompt.
// Console is also provided by platform.
void platform_console_write(char const* message, u8 color /*corresponding to log level*/);
void platform_console_write_error(char const* message, u8 color /*corresponding to log level*/);

// Get the actual time since the application has actually been running.
// In second unit.
f64 platform_get_absolute_time();

// Sleep on the thread for the provided ms. This blocks the main thread.
// Should only be used for giving time back to the OS for unused update power.
// Therefore it is not exported.
void platform_sleep(u64 ms);
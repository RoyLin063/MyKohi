#pragma once
// We name this file "asserts.h",
// because assert.h is a standard library header.

#include "defines.h"

// Disable assertions by commenting out the below line.
#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

KAPI void report_assertion_failure(char const* expression,
    char const* message, char const* file, i32 line);


#define KASSERT(expr)                                           \
{                                                               \
    if(expr)                                                    \
    {                                                           \
                                                                \
    }                                                           \
    else                                                        \
    {                                                           \
        report_assertion_failure(#expr, "", __FILE__, __LINE__);\
        debugBreak();                                           \
    }                                                           \
}

#define KASSERT_MSG(expr, message)                                            \
{                                                                             \
    if (expr)                                                                 \
    {                                                                         \
                                                                              \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        report_assertion_failure(#expr, message, __FILE__, __LINE__);         \
        debugBreak();                                                         \
    }                                                                         \
}

#ifdef __debugbreak                                             
#define KASSERT_DEBUG(expr)                                     \
{                                                               \
    if(expr)                                                    \
    {                                                           \
                                                                \
    }                                                           \
    else                                                        \
    {                                                           \
        report_assertion_failure(#expr, "", __FILE__, __LINE__);\
        debugBreak();                                           \
    }                                                           \
}
#else
#define KASSERT_DEBUG(expr)     // Does nothing at all
#endif

#endif
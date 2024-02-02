#include "core/kstring.h"
#include "core/kmemory.h"

#include <string.h>

u64 string_length(char const* str)
{
    return strlen(str);
}

char* string_duplicate(char const* str)
{
    u64 length = string_length(str);
    char* copy = kallocate(length + 1, MEMORY_TAG_STRING);
    kcopy_memory(copy, str, length + 1);
    return copy;
}

b8 strings_equal(char const* str0, char const* str1)
{
    return strcmp(str0, str1) == 0;
}
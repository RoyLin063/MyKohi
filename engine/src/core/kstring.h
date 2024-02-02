#pragma once

#include "defines.h"

// Returns the length of the given string.
KAPI u64 string_length(char const* str);

KAPI char* string_duplicate(char const* str);


// Case sensitive string comparison. True if the same otherwise false.
KAPI b8 strings_equal(char const* str0, char const* str1);
#pragma once
// define vulkan specific types for everything.
#include "defines.h"

// Don't need to include vulkan.h anywhere
#include <vulkan/vulkan.h>

typedef struct vulkan_context
{
    VkInstance instance;
    VkAllocationCallbacks* allocator;
} vulkan_context;
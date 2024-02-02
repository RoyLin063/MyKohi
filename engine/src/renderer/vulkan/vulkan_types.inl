#pragma once
// define vulkan specific types for everything.
#include "defines.h"
#include "core/asserts.h"

// Don't need to include vulkan.h anywhere
#include <vulkan/vulkan.h>

// Checks the given expression's return value against VK_SUCCESS.
#define VK_CHECK(expr)                  \
{                                       \
    KASSERT(expr == VK_SUCCESS);        \
}

typedef struct vulkan_context
{
    VkInstance instance;
    VkAllocationCallbacks* allocator;

#if defined(_DEBUG)
    VkDebugUtilsMessengerEXT debug_messenger;
#endif
} vulkan_context;
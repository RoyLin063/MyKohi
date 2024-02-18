#pragma once

#include "vulkan_types.inl"


// What a render pass is?
// Tell vulkan about the frame buffer attachments.
// Also including formatting informations and
// how many samples it uses.
// Subpass:
// subsequent rendering operations can depend something done 
// in a previous subpass.
void vulkan_renderpass_create(
    vulkan_context* context,
    vulkan_renderpass* out_renderpass,
    f32 x, f32 y, f32 w, f32 h,             // render area
    f32 r, f32 g, f32 b, f32 a,             // clear color
    f32 depth,
    u32 stencil
);

void vulkan_renderpass_destroy(vulkan_context* context, vulkan_renderpass* renderpass);

void vulkan_renderpass_begin(
    vulkan_command_buffer* command_buffer,
    vulkan_renderpass* renderpass,
    VkFramebuffer frame_buffer
);

void vulkan_renderpass_end(vulkan_command_buffer* command_buffer, vulkan_renderpass* renderpass);
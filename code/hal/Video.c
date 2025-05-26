/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
// #include <stdlib.h>
#include <string.h>
#include "hal/Interrupt.h"
#include "hal/Timer.h"
#include "hal/Video.h"

#define MAX_WIDTH 720
#define MAX_HEIGHT 720

#define VIDEO_DATA_BASE     (VIDEO_BASE + 0x00000000)
#define VIDEO_PALETTE_BASE  (VIDEO_BASE + 0x00e00000)
#define VIDEO_CONTROL_BASE	(VIDEO_BASE + 0x00f00000)

static void* s_primary_target = 0;
static uint32_t s_visible_offset = 0;
static uint32_t s_hidden_offset = MAX_WIDTH * MAX_HEIGHT;
static int32_t s_mode = 0;

static const struct
{
	int32_t width;
	int32_t height;
	int32_t pixels;
	uint8_t skip;
}
c_modes[] =
{
	{ 720, 720, 720 * 720, 0b00 }
};

int32_t video_init()
{
	s_primary_target = (uint32_t*)VIDEO_DATA_BASE;
	video_set_mode(VMODE_720_720_8);
	return 0;
}

int32_t video_set_mode(int32_t mode)
{
	volatile uint32_t* control = (volatile uint32_t*)VIDEO_CONTROL_BASE;
	control[1] = c_modes[mode].width;
	control[2] = c_modes[mode].skip;
	s_mode = mode;
}

void* video_create_target()
{
	// void* target = malloc(c_modes[s_mode].pixels);
	// memset(target, 0, c_modes[s_mode].pixels);
	// return target;
	return 0;
}

void video_destroy_target(void* target)
{
	// free(target);
}

int32_t video_get_resolution_width()
{
	return c_modes[s_mode].width;
}

int32_t video_get_resolution_height()
{
	return c_modes[s_mode].height;
}

void video_set_palette(uint8_t index, uint32_t color)
{
	volatile uint32_t* palette = (volatile uint32_t*)VIDEO_PALETTE_BASE;
	palette[index] = color;
}

void* video_get_primary_target()
{
	uint8_t* ptr = (uint8_t*)s_primary_target;
	return ptr + s_visible_offset;
}

void* video_get_secondary_target()
{
	uint8_t* ptr = (uint8_t*)s_primary_target;
	return ptr + s_hidden_offset;
}

void video_clear(uint8_t idx)
{
	uint8_t* framebuffer = (uint8_t*)video_get_secondary_target();
	memset(framebuffer, idx, c_modes[s_mode].pixels);
}

void video_blit(const void* source)
{
	uint8_t* target = (uint8_t*)video_get_secondary_target();
	memcpy(target, source, c_modes[s_mode].pixels);
}

void video_present()
{
	// Swap offsets.
	const uint32_t tmp = s_hidden_offset;
	s_hidden_offset = s_visible_offset;
	s_visible_offset = tmp;

	// Set video offset to start reading from previously hidden part.
	volatile uint32_t* control = (volatile uint32_t*)VIDEO_CONTROL_BASE;
	control[0] = s_visible_offset;
}

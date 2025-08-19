/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
// #include <stdlib.h>
#include <string.h>
#include "HAL/Interrupt.h"
#include "HAL/Timer.h"
#include "HAL/Video.h"

#define MAX_WIDTH 720
#define MAX_HEIGHT 720

#define VIDEO_DATA_BASE     (VIDEO_BASE + 0x00000000)
#define VIDEO_PALETTE_BASE  (VIDEO_BASE + 0x00e00000)
#define VIDEO_CONTROL_BASE	(VIDEO_BASE + 0x00f00000)

static void* s_primary_target = 0;
static uint32_t s_visible_offset = 0;
static uint32_t s_hidden_offset = 0;
static int32_t s_mode = 0;

static const struct
{
	int32_t width;
	int32_t height;
	uint8_t skip;
	uint8_t skipH;
	uint8_t skipV;
	uint8_t palette;
	uint32_t page;
}
c_modes[] =
{
	{ 720, 720, 0b00, 0, 0, 1, 720 * 720 },
	{ 360, 360, 0b11, 0, 0, 1, 360 * 360 },
	{ 320, 200, 0b11, 40, 160, 1, 320 * 200 },
	{ 720, 720, 0b00, 0, 0, 0, 720 * 720 * 4 },		//!< Not enought VRAM for double buffering.
	{ 360, 360, 0b11, 0, 0, 0, 360 * 360 * 4 },
	{ 320, 200, 0b11, 40, 160, 0, 320 * 200 * 4 }
};

int32_t hal_video_init()
{
	s_primary_target = (uint32_t*)VIDEO_DATA_BASE;
	hal_video_set_mode(VMODE_720_720_8);
	return 0;
}

int32_t hal_video_set_mode(int32_t mode)
{
	volatile uint32_t* control = (volatile uint32_t*)VIDEO_CONTROL_BASE;
	
	// Setup video output.
	control[1] = c_modes[mode].width;	// 4
	control[2] = c_modes[mode].skip;	// 8
	control[3] = c_modes[mode].skipH;	// 12
	control[4] = c_modes[mode].skipV;	// 16
	control[5] = c_modes[mode].palette;	// 20

	// Initial offset to secondary page.
	s_hidden_offset = c_modes[mode].page;
	s_mode = mode;
}

int32_t hal_video_get_resolution_width()
{
	return c_modes[s_mode].width;
}

int32_t hal_video_get_resolution_height()
{
	return c_modes[s_mode].height;
}

uint32_t hal_video_get_page_size()
{
	return c_modes[s_mode].page;
}

void hal_video_set_palette(uint8_t index, uint32_t color)
{
	volatile uint32_t* palette = (volatile uint32_t*)VIDEO_PALETTE_BASE;
	palette[index] = color;
}

void* hal_video_get_primary_target()
{
	uint8_t* ptr = (uint8_t*)s_primary_target;
	return ptr + s_visible_offset;
}

void* hal_video_get_secondary_target()
{
	uint8_t* ptr = (uint8_t*)s_primary_target;
	return ptr + s_hidden_offset;
}

void hal_video_present()
{
	// Swap offsets.
	const uint32_t tmp = s_hidden_offset;
	s_hidden_offset = s_visible_offset;
	s_visible_offset = tmp;

	// Set video offset to start reading from previously hidden part.
	volatile uint32_t* control = (volatile uint32_t*)VIDEO_CONTROL_BASE;
	control[0] = s_visible_offset;
}

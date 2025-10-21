/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/Sprite.h"

#define SPRITE_WIDTH			64
#define SPRITE_HEIGHT			64
#define SPRITE_REGISTERS_BASE	(SPRITE_BASE)
#define SPRITE_BITS_BASE		(SPRITE_BASE + 0x4000)
#define SPRITE_REGISTERS(N)		((volatile uint32_t*)SPRITE_REGISTERS_BASE + N * 4)
#define SPRITE_BITS(N)			((volatile uint32_t*)SPRITE_BITS_BASE + N * 0x4000)

void hal_sprite_set_visible(int32_t index, int8_t visible)
{
	volatile uint32_t* s = SPRITE_REGISTERS(index);
	s[2] = visible;
}

void hal_sprite_set_position(int32_t index, int32_t x, int32_t y)
{
	volatile uint32_t* s = SPRITE_REGISTERS(index);
	s[0] = x;
	s[1] = y;
}

void hal_sprite_set_bits(int32_t index, const void* bits, int32_t width, int32_t height)
{
	volatile uint32_t* p = SPRITE_BITS(index);
	const uint8_t* s = (const uint8_t*)bits;

	if (width > SPRITE_WIDTH)
		width = SPRITE_WIDTH;
	if (height > SPRITE_HEIGHT)
		height = SPRITE_HEIGHT;

	// Copy bits into sprite memory; note each pixel
	// in sprite memory are written as 32-bit values
	// but only lowest signifact byte is used.
	for (int32_t y = 0; y < height; ++y)
	{
		for (int32_t x = 0; x < width; ++x)
		{
			*p++ = *s++;
		}
		for (int32_t x = width; x < SPRITE_WIDTH; ++x)
			*p++ = 0xff;
	}
	for (int32_t y = height; y < SPRITE_HEIGHT; ++y)
	{
		for (int32_t x = 0; x < SPRITE_WIDTH; ++x)
			*p++ = 0xff;
	}
}

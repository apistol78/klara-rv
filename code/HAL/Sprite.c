/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/Sprite.h"

#define SPRITE_DATA(N) ((volatile uint32_t*)(SPRITE_BASE) + N * 2)

void hal_sprite_set_position(int32_t index, int32_t x, int32_t y)
{
	volatile uint32_t* s = SPRITE_DATA(index);
	s[0] = x;
	s[1] = y;
}

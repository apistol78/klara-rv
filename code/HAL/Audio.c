/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/Audio.h"

void hal_audio_init()
{
	hal_audio_set_playback_rate(22050);
}

void hal_audio_set_playback_rate(uint32_t rate)
{
	volatile int32_t* audio = (volatile int32_t*)AUDIO_BASE;
	audio[1] = rate;
}

uint32_t hal_audio_get_queued()
{
	return *(volatile uint32_t*)AUDIO_BASE;
}


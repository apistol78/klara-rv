/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include "HAL/Common.h"

#define HAL_AUDIO_MODE_APPEND   0x00000000
#define HAL_AUDIO_MODE_REPLACE  0x10000000
#define HAL_AUDIO_MODE_MONO		0x00000000
#define HAL_AUDIO_MODE_STEREO	0x20000000

EXTERN_C void hal_audio_init();

EXTERN_C void hal_audio_set_playback_rate(uint32_t rate);

EXTERN_C uint32_t hal_audio_get_channels_busy();

EXTERN_C void hal_audio_setup_channel(uint8_t channel, const void* samples, uint32_t nsamples, uint32_t mode);


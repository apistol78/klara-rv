/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <stdint.h>

#define CPU_FREQUENCY 100000000

#define UART_BASE	  0x20000000
#define I2C_BASE	  0x30000000
#define SD_BASE		  0x40000000
#define TIMER_BASE	  0x50000000
#define AUDIO_BASE	  0x60000000
#define PLIC_BASE	  0x70000000
#define VIDEO_BASE    0x80000000
#define DMA_BASE      0x90000000
#define SPRITE_BASE   0xa0000000
#define SPI_BASE      0xb0000000

#define NO_OPTIMIZE	__attribute__((optimize("O0")))

#if defined(__cplusplus)
#   define EXTERN_C	extern "C"
#else
#   define EXTERN_C
#endif

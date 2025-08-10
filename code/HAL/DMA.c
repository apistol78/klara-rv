/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/DMA.h"

#define DMA_FROM    (volatile uint32_t*)(DMA_BASE)
#define DMA_TO		(volatile uint32_t*)(DMA_BASE + 4)
#define DMA_COUNT	(volatile uint32_t*)(DMA_BASE + 8)
#define DMA_RUN		(volatile uint32_t*)(DMA_BASE + 12)

uint32_t hal_dma_write(void* dst, uint32_t count, uint32_t value)
{
	*DMA_FROM = value;
	*DMA_TO = (uint32_t)dst;
	*DMA_COUNT = count;
	*DMA_RUN = 1;
	return 0;
}

uint32_t hal_dma_copy(void* dst, const void* src, uint32_t count)
{
	*DMA_FROM = (uint32_t)src;
	*DMA_TO = (uint32_t)dst;
	*DMA_COUNT = count;
	*DMA_RUN = 2;
	return 0;
}

uint8_t hal_dma_is_busy()
{
	return (*DMA_RUN != 0) ? 1 : 0;
}

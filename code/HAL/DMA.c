/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/DMA.h"

#define DMA_FROM	((volatile uint32_t*)(DMA_BASE) + 0)
#define DMA_TO		((volatile uint32_t*)(DMA_BASE) + 1)
#define DMA_COUNT	((volatile uint32_t*)(DMA_BASE) + 2)
#define DMA_RUN		((volatile uint32_t*)(DMA_BASE) + 3)
#define DMA_PITCH	((volatile uint32_t*)(DMA_BASE) + 4)
#define DMA_WIDTH	((volatile uint32_t*)(DMA_BASE) + 5)

uint32_t hal_dma_write(void* dst, uint32_t count, uint32_t value)
{
	*DMA_FROM = value;
	*DMA_TO = (uint32_t)dst;
	*DMA_COUNT = count;
	*DMA_RUN = 1;
	return *DMA_FROM;
}

uint32_t hal_dma_copy(void* dst, const void* src, uint32_t count)
{
	*DMA_FROM = (uint32_t)src;
	*DMA_TO = (uint32_t)dst;
	*DMA_COUNT = count;
	*DMA_RUN = 2;
	return *DMA_FROM;
}

uint32_t hal_dma_feed(void* dst, const void* src, uint32_t count)
{
	*DMA_FROM = (uint32_t)src;
	*DMA_TO = (uint32_t)dst;
	*DMA_COUNT = count;
	*DMA_RUN = 3;
	return *DMA_FROM;
}

uint32_t hal_dma_blit(void* dst, const void* src, uint32_t width, uint32_t height, uint32_t pitch)
{
	*DMA_FROM = (uint32_t)src;
	*DMA_TO = (uint32_t)dst;
	*DMA_WIDTH = width;
	*DMA_COUNT = height;
	*DMA_PITCH = pitch;
	*DMA_RUN = 4;
	return *DMA_FROM;
}

uint8_t hal_dma_is_busy()
{
	const uint32_t state = *DMA_RUN;
	return ((state & 1) != 0) ? 1 : 0;
}

uint8_t hal_dma_is_full()
{
	const uint32_t state = *DMA_RUN;
	return ((state & 2) != 0) ? 1 : 0;
}

uint32_t hal_dma_retired()
{
	return *DMA_TO;
}

/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/DMA.h"

#define DMA_BASE_(B, C)	((volatile uint32_t*)((B) | (C)))
#define DMA_FROM(B, C)	(DMA_BASE_(B, C) + 0)
#define DMA_TO(B, C)	(DMA_BASE_(B, C) + 1)
#define DMA_COUNT(B, C)	(DMA_BASE_(B, C) + 2)
#define DMA_RUN(B, C)	(DMA_BASE_(B, C) + 3)
#define DMA_PITCH(B, C)	(DMA_BASE_(B, C) + 4)
#define DMA_WIDTH(B, C)	(DMA_BASE_(B, C) + 5)

uint32_t hal_dma_write(uint32_t base, uint32_t channel, void* dst, uint32_t count, uint32_t value)
{
	*DMA_FROM(base, channel) = value;
	*DMA_TO(base, channel) = (uint32_t)dst;
	*DMA_COUNT(base, channel) = count;
	*DMA_RUN(base, channel) = 1;
	return *DMA_FROM(base, channel);
}

uint32_t hal_dma_copy(uint32_t base, uint32_t channel, void* dst, const void* src, uint32_t count)
{
	*DMA_FROM(base, channel) = (uint32_t)src;
	*DMA_TO(base, channel) = (uint32_t)dst;
	*DMA_COUNT(base, channel) = count;
	*DMA_RUN(base, channel) = 2;
	return *DMA_FROM(base, channel);
}

uint32_t hal_dma_feed(uint32_t base, uint32_t channel, void* dst, const void* src, uint32_t count)
{
	*DMA_FROM(base, channel) = (uint32_t)src;
	*DMA_TO(base, channel) = (uint32_t)dst;
	*DMA_COUNT(base, channel) = count;
	*DMA_RUN(base, channel) = 3;
	return *DMA_FROM(base, channel);
}

uint32_t hal_dma_blit(uint32_t base, uint32_t channel, void* dst, const void* src, uint32_t width, uint32_t height, uint32_t pitch)
{
	*DMA_FROM(base, channel) = (uint32_t)src;
	*DMA_TO(base, channel) = (uint32_t)dst;
	*DMA_WIDTH(base, channel) = width;
	*DMA_COUNT(base, channel) = height;
	*DMA_PITCH(base, channel) = pitch;
	*DMA_RUN(base, channel) = 4;
	return *DMA_FROM(base, channel);
}

uint8_t hal_dma_is_busy(uint32_t base, uint32_t channel)
{
	const uint32_t state = *DMA_RUN(base, channel);
	return ((state & 1) != 0) ? 1 : 0;
}

uint8_t hal_dma_is_full(uint32_t base, uint32_t channel)
{
	const uint32_t state = *DMA_RUN(base, channel);
	return ((state & 2) != 0) ? 1 : 0;
}

uint32_t hal_dma_retired(uint32_t base, uint32_t channel)
{
	return *DMA_TO(base, channel);
}

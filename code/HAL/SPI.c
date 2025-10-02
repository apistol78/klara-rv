/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <stdio.h>
#include "HAL/SPI.h"

#define SPI_DATA (volatile uint32_t*)(SPI_BASE)
#define SPI_CTRL (volatile uint32_t*)(SPI_BASE + 4)

static void hal_spi_wait_until_idle()
{
	for (;;)
	{
		const uint32_t status = *SPI_CTRL;
		if ((status & 0x1) == 0x1)
			break;
	}
}

void hal_spi_begin(uint8_t rxEnable)
{
	hal_spi_wait_until_idle();
	*SPI_CTRL = 1 | (rxEnable ? 2 : 0);
}

void hal_spi_end()
{
	hal_spi_wait_until_idle();
	*SPI_CTRL = 0;
}

void hal_spi_write(uint8_t data)
{
	*SPI_DATA = (uint32_t)data;
}

uint8_t hal_spi_read()
{
    return (uint8_t)*SPI_DATA;
}

void hal_spi_clear()
{
	for (;;)
	{
		const uint32_t status = *SPI_CTRL;
		if ((status & 0x10) == 0x10)
			break;
		hal_spi_read();
	}
}

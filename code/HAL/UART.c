/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/UART.h"

volatile uint32_t* const c_base = (volatile uint32_t*)UART_BASE;
volatile uint32_t* const c_status = (volatile uint32_t*)(UART_BASE + 0x04);

void hal_uart_tx_u8(uint8_t data)
{
	*c_base = (uint32_t)data;
}

uint32_t hal_uart_rx_full()
{
	return (*c_status & 0x00000001) ? 1 : 0;
}

uint32_t hal_uart_rx_empty()
{
	return (*c_status & 0x00000002) ? 1 : 0;
}

uint8_t hal_uart_rx_u8()
{
	return (uint8_t)*c_base;
}

uint16_t hal_uart_rx_u16()
{
	uint16_t value = 0;
	uint8_t* tmp = (uint8_t*)&value;
	tmp[0] = hal_uart_rx_u8();
	tmp[1] = hal_uart_rx_u8();
	return value;
}

uint32_t hal_uart_rx_u32()
{
	uint32_t value = 0;
	uint8_t* tmp = (uint8_t*)&value;
	tmp[0] = hal_uart_rx_u8();
	tmp[1] = hal_uart_rx_u8();
	tmp[2] = hal_uart_rx_u8();
	tmp[3] = hal_uart_rx_u8();
	return value;
}

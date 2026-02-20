/*
 Klara-RTL
 Copyright (c) 2025-2026 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/I2C.h"

#define I2C_CTRL (volatile uint32_t*)(I2C_BASE)
#define I2C_DATA (volatile uint32_t*)(I2C_BASE + 4)

#define I2C_STATUS_RX_QUEUE_FULL	0x00000001
#define I2C_STATUS_RX_QUEUE_EMPTY	0x00000002
#define I2C_STATUS_CMD_BUSY			0x00000010

int32_t hal_i2c_idle()
{
	const uint32_t status = *I2C_CTRL;
	return (status & I2C_STATUS_CMD_BUSY) ? 0 : 1;
}

int32_t hal_i2c_have_read_data()
{
	const uint32_t status = *I2C_CTRL;
	return (status & I2C_STATUS_RX_QUEUE_EMPTY) ? 0 : 1;
}

void hal_i2c_write(uint8_t deviceAddr, uint8_t controlAddr, uint8_t controlData, int32_t mode)
{
	*I2C_CTRL = 
		((uint32_t)controlData << 24) |
		((uint32_t)controlAddr << 16) |
		((uint32_t)deviceAddr << 8) |
		(mode ? 0x02 : 0x00) |
		0x1;
}

void hal_i2c_read(uint8_t deviceAddr, uint8_t controlAddr, uint8_t nbytes, int32_t mode)
{
	*I2C_CTRL = 
		((uint32_t)nbytes << 24) |
		((uint32_t)controlAddr << 16) |
		((uint32_t)deviceAddr << 8) |
		(mode ? 0x02 : 0x00) |
		0x0;
}

void hal_i2c_read_get(uint8_t* outControlData, uint8_t nbytes)
{
	for (uint8_t i = 0; i < nbytes; ++i)
		outControlData[i] = *I2C_DATA;
}

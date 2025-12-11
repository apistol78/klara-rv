/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/I2C.h"

#define I2C_CTRL (volatile uint32_t*)(I2C_BASE)
#define I2C_DATA (volatile uint32_t*)(I2C_BASE + 4)
#define I2C_QUEUED (volatile uint32_t*)(I2C_BASE + 8)
#define I2C_RETIRED (volatile uint32_t*)(I2C_BASE + 12)

#define I2C_STATUS_RX_QUEUE_FULL	0x00000001
#define I2C_STATUS_RX_QUEUE_EMPTY	0x00000002
#define I2C_STATUS_CMD_QUEUE_FULL	0x00000004
#define I2C_STATUS_CMD_QUEUE_EMPTY	0x00000008
#define I2C_STATUS_CMD_QUEUE_BUSY	0x00000010

static void hal_i2c_wait_until_idle()
{
	for (;;)
	{
		const uint32_t status = *I2C_CTRL;
		if ((status & I2C_STATUS_CMD_QUEUE_BUSY) == 0)
			break;
	}
}

uint32_t hal_i2c_write(uint8_t deviceAddr, uint8_t controlAddr, uint8_t controlData, int32_t mode)
{
	*I2C_CTRL = 
		((uint32_t)controlData << 24) |
		((uint32_t)controlAddr << 16) |
		((uint32_t)deviceAddr << 8) |
		//(mode ? 0x04 : 0x00) |
		0x02;
	const uint32_t tag = *I2C_QUEUED;
	return tag;
}

uint32_t hal_i2c_read(uint8_t deviceAddr, uint8_t controlAddr, uint8_t nbytes, int32_t mode)
{
	*I2C_CTRL = 
		((uint32_t)nbytes << 24) |
		((uint32_t)controlAddr << 16) |
		((uint32_t)deviceAddr << 8) |
		//(mode ? 0x04 : 0x00) |
		0x01;
	const uint32_t tag = *I2C_QUEUED;
	return tag;
}

void hal_i2c_read_get(uint8_t* outControlData, uint8_t nbytes)
{
	for (uint8_t i = 0; i < nbytes; ++i)
		outControlData[i] = *I2C_DATA;
}

uint32_t hal_i2c_retired()
{
	return *I2C_RETIRED;
}

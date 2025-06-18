/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/I2C.h"

#define I2C_CTRL (volatile uint32_t*)(I2C_BASE)

int32_t NO_OPTIMIZE hal_i2c_write(uint8_t deviceAddr, uint8_t controlAddr, uint8_t controlData)
{
	*I2C_CTRL =
		(0x00U << 24) |
		(((uint32_t)deviceAddr) << 16) |
		(((uint32_t)controlAddr) << 8) |
		controlData;

	return 0;
}

int32_t NO_OPTIMIZE hal_i2c_read(uint8_t deviceAddr, uint8_t controlAddr, uint8_t* outControlData, uint8_t nbytes)
{
	*I2C_CTRL =
		(0x01U << 24) |
		(((uint32_t)deviceAddr) << 16) |
		(((uint32_t)controlAddr) << 8) |
		nbytes;

	for (int32_t i = 0; i < nbytes; ++i)
		outControlData[i] = *I2C_CTRL;

	return 0;
}

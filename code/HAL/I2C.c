/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/I2C.h"
#include "HAL/Timer.h"

#define I2C_CTRL (volatile uint32_t*)(I2C_BASE)

#define I2C_RD_SDA() \
	((*I2C_CTRL & 1) == 1)
#define I2C_WR_SDA_LOW() \
	{ *I2C_CTRL = 0x0010; }
#define I2C_WR_SDA_HIGH() \
	{ *I2C_CTRL = 0x0011; }

#define I2C_RD_SCL() \
	((*I2C_CTRL & 2) == 2)
#define I2C_WR_SCL_LOW() \
	{ *I2C_CTRL = 0x0020; }
#define I2C_WR_SCL_HIGH() \
	{ *I2C_CTRL = 0x0022; }

static void hal_i2c_dly()
{
	for (uint32_t i = 0; i < 80; ++i)
		__asm__ volatile ("nop");
}

static void hal_i2c_start()
{
	I2C_WR_SDA_HIGH();	// i2c start bit sequence
	hal_i2c_dly();
	I2C_WR_SCL_HIGH();
	hal_i2c_dly();
	I2C_WR_SDA_LOW();
	hal_i2c_dly();
	I2C_WR_SCL_LOW();
	hal_i2c_dly();
}

static void hal_i2c_stop()
{
	I2C_WR_SDA_LOW();	// i2c stop bit sequence
	hal_i2c_dly();
	I2C_WR_SCL_HIGH();
	hal_i2c_dly();
	I2C_WR_SDA_HIGH();
	hal_i2c_dly();
}

static uint8_t hal_i2c_rx(uint8_t ack)
{
	uint8_t x, d = 0;

	I2C_WR_SDA_HIGH(); 
	for (x = 0; x < 8; x++)
	{
		d <<= 1;
		
		const uint32_t ms = hal_timer_get_ms();
		do
		{
			if ((hal_timer_get_ms() - ms) > 10)
				break;
			I2C_WR_SCL_HIGH();
		}
		while (I2C_RD_SCL() == 0);    // wait for any SCL clock stretching

		hal_i2c_dly();
		if (I2C_RD_SDA())
			d |= 1;
		I2C_WR_SCL_LOW();
		hal_i2c_dly();
	} 

	if (ack)
		{ I2C_WR_SDA_LOW(); }
	else
		{ I2C_WR_SDA_HIGH(); }

	hal_i2c_dly();
	I2C_WR_SCL_HIGH();
	hal_i2c_dly();	// send (N)ACK bit
	I2C_WR_SCL_LOW();
	I2C_WR_SDA_HIGH();
	return d;
}

static uint8_t NO_OPTIMIZE hal_i2c_tx_addr(uint8_t d, uint8_t bits, uint8_t read)
{
	const uint8_t od = d;

	for (uint8_t i = 0; i < bits; ++i)
	{
		if (d & 0x40)
			{ I2C_WR_SDA_HIGH(); }
		else
			{ I2C_WR_SDA_LOW(); }

		hal_i2c_dly();

		I2C_WR_SCL_HIGH();
		hal_i2c_dly();
		I2C_WR_SCL_LOW();
		hal_i2c_dly();

		d <<= 1;
	}

	// R/W bit
	{
		if (read)
			{ I2C_WR_SDA_HIGH(); }
		else
			{ I2C_WR_SDA_LOW(); }

		hal_i2c_dly();

		I2C_WR_SCL_HIGH();
		hal_i2c_dly();
		I2C_WR_SCL_LOW();
		hal_i2c_dly();			
	}

	// ACK/NAK
	I2C_WR_SDA_HIGH();
	hal_i2c_dly();
	I2C_WR_SCL_HIGH();
	hal_i2c_dly();
	const uint8_t b = I2C_RD_SDA();
	I2C_WR_SCL_LOW();
	hal_i2c_dly();

	// High means NAK.
	// if (b)
	// 	printf("[%02x] no ack\n", od);

	return b;
}

static uint8_t NO_OPTIMIZE hal_i2c_tx_data(uint8_t d)
{
	for (uint8_t i = 0; i < 8; ++i)
	{
		if (d & 0x80)
			{ I2C_WR_SDA_HIGH(); }
		else
			{ I2C_WR_SDA_LOW(); }

		hal_i2c_dly();

		I2C_WR_SCL_HIGH();
		hal_i2c_dly();
		I2C_WR_SCL_LOW();
		hal_i2c_dly();

		d <<= 1;
	}

	// ACK/NAK
	I2C_WR_SDA_HIGH();
	hal_i2c_dly();
	I2C_WR_SCL_HIGH();
	hal_i2c_dly();
	const uint8_t b = I2C_RD_SDA();
	I2C_WR_SCL_LOW();
	hal_i2c_dly();

	return b;
}

int32_t hal_i2c_write(uint8_t deviceAddr, uint8_t controlAddr, uint8_t controlData)
{
	hal_i2c_start();
	hal_i2c_tx_addr(deviceAddr, 7, 0);
	hal_i2c_tx_data(controlAddr);
	hal_i2c_tx_data(controlData);
	hal_i2c_stop();
	return 0;
}

int32_t hal_i2c_read(uint8_t deviceAddr, uint8_t controlAddr, uint8_t* outControlData, uint8_t nbytes)
{
	hal_i2c_start();
	hal_i2c_tx_addr(deviceAddr, 7, 0);
	hal_i2c_tx_data(controlAddr);

	hal_i2c_start();  // restart
	hal_i2c_tx_addr(deviceAddr, 7, 1);
	for (uint8_t i = 0; i < nbytes; ++i)
		outControlData[i] = hal_i2c_rx((i < nbytes - 1) ? 1 : 0);  // read
	hal_i2c_stop();

	return 0;
}

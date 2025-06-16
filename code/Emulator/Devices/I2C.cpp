/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "Emulator/Devices/I2C.h"

namespace
{

#define SDA(ctrl) ((ctrl) & 1)
#define SCL(ctrl) ((ctrl) & 2)

}

T_IMPLEMENT_RTTI_CLASS(L"I2C", I2C, IDevice)

bool I2C::writeU32(uint32_t address, uint32_t value)
{
	const uint8_t la = address & 0xff;
	switch (la)
	{
	case 0:
		m_ctrl &= ~(value >> 4);
		m_ctrl |= (value & 3);
		break;
	}
	return true;
}

uint32_t I2C::readU32(uint32_t address) const
{
	const uint8_t la = address & 0xff;
	switch (la)
	{
	case 0:
		return m_ctrl;
	}
	return 0;
}

bool I2C::tick(CPU* cpu)
{
	m_last = m_ctrl;
	return true;
}

/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>

#include "Emulator/Devices/I2C.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"I2C", I2C, IDevice)

T_IMPLEMENT_RTTI_CLASS(L"I2C.ISlave", I2C::ISlave, Object)

bool I2C::writeU32(uint32_t address, uint32_t value)
{
	const uint8_t dir = (value >> 24);
	const uint8_t deviceAddr = (value >> 16) & 255;
	const uint8_t controlAddr = (value >> 8) & 255;
	const uint8_t controlDataOrCount = value & 255;

	ISlave* slave = m_slaves[deviceAddr];
	if (!slave)
	{
		log::info << L"[I2C] No device " << str(L"0x%08x§x", value) << L" attached to I2C bus." << Endl;
		return true;
	}

	if (dir == 0x00)	// write
	{
		slave->write(controlAddr, controlDataOrCount);
	}
	else if (dir == 0x01 && controlDataOrCount < 16)	// read
	{
		uint8_t data[16];
		slave->read(controlAddr, controlDataOrCount, data);
		for (uint8_t i = 0; i < controlDataOrCount; ++i)
			m_data.push_back(data[i]);
	}

	return true;
}

uint32_t I2C::readU32(uint32_t address) const
{
	if (!m_data.empty())
	{
		const uint8_t value = m_data.front();
		m_data.pop_front();
		return value;
	}
	else
		return 0;
}

bool I2C::tick(CPU* cpu)
{
	bool result = true;
	for (auto slave : m_slaves)
	{
		if (slave.second)
			result &= slave.second->tick(cpu);
	}
	return result;
}

void I2C::addSlave(uint8_t address, ISlave* slave)
{
	m_slaves[address] = slave;
}
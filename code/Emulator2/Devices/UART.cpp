/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>

#include "Emulator2/Devices/UART.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"UART", UART, IDevice)

void UART::enqueue(uint8_t b)
{
	if (m_data.full())
		m_data.pop_front();
	m_data.push_back(b);
}

bool UART::writeU32(uint32_t address, uint32_t value)
{
	log::info << wchar_t(value & 0xff);
	return true;
}

uint32_t UART::readU32(uint32_t address) const
{
	if (address == 0x00)
	{
		if (!m_data.empty())
		{
			const uint8_t b = m_data.front();
			m_data.pop_front();
			return b;
		}
		else
			return 0;
	}
	else if (address == 0x04)
	{
		return m_data.empty() ? 0x00000002 : 0x00000000;
	}
	else
		return 0;
}

bool UART::tick(ICPU* cpu)
{
	return true;
}

/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>

#include "Emulator2/Devices/Timer.h"

namespace tk = traktor;

T_IMPLEMENT_RTTI_CLASS(L"Timer", Timer, IDevice)

Timer::Timer()
{
	m_callback = [](){};
}

bool Timer::writeU32(uint32_t address, uint32_t value)
{
	switch (address >> 2)
	{
	case 0x3:
		m_compare = (m_compare & 0xffffffff00000000) | value;
		break;

	case 0x4:
		m_compare = (m_compare & 0x00000000ffffffff) | ((uint64_t)value << 32ULL);
		break;

	case 0x5:
		m_countdown = value;
		break;

	default:
		tk::log::error << L"[Timer] attempt write to unknown address " << tk::str(L"0x%08x", address) << L"." << tk::Endl;
		return false;
	}
	return true;
}

uint32_t Timer::readU32(uint32_t address) const
{
	switch (address >> 2)
	{
	case 0x0:
		return (uint32_t)(m_timer.getElapsedTime() * 1000.0);

	case 0x1:
		return (uint32_t)m_cycles;			// cycles low

	case 0x2:
		return (uint32_t)(m_cycles >> 32);	// cycles high

	case 0x3:
		return (uint32_t)m_compare;			// compare low

	case 0x4:
		return (uint32_t)(m_compare >> 32);	// compare high

	case 0x5:
		return m_countdown;

	default:
		tk::log::error << L"[Timer] attempt read from unknown address " << tk::str(L"0x%08x", address) << L"." << tk::Endl;
		return 0;
	}
	return 0;
}

bool Timer::tick(ICPU* cpu, Bus* bus)
{
	const int32_t cyclesPerTick = 1;
	for (int32_t i = 0; i < cyclesPerTick; ++i)
	{
		if (++m_cycles == m_compare && m_compare != 0)
			m_callback();

		if (m_countdown > 0)
		{
			if (--m_countdown == 0)
				m_callback();
		}
	}
	return true;
}

void Timer::setCallback(const std::function< void() >& callback)
{
	m_callback = callback;
}

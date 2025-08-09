/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>

#include "Emulator2/CPU/Bus.h"
#include "Emulator2/Devices/DMA.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"DMA", DMA, IDevice)

bool DMA::writeU32(uint32_t address, uint32_t value)
{
	if (address == 0)
		m_from = value & ~3U;
	else if (address == 4)
		m_to = value & ~3U;
	else if (address == 8)
		m_count = value;
	else if (address == 12)
		m_run = value;
	return true;
}

uint32_t DMA::readU32(uint32_t address) const
{
	if (address == 12)
		return m_run ? 1 : 0;
	else
		return 0;
}

bool DMA::tick(ICPU* cpu, Bus* bus)
{
	if (m_run == 1)
	{
		if (m_count > 0)
		{
			const uint32_t value = m_from;
			bus->writeU32(m_to, value);
			m_to += 4;
			m_count--;
		}
	}
	else if (m_run == 2)
	{
		if (m_count > 0)
		{
			const uint32_t value = bus->readU32(m_from);
			bus->writeU32(m_to, value);
			m_to += 4;
			m_from += 4;
			m_count--;
		}
	}
	if (m_count == 0)
		m_run = 0;
	return true;
}

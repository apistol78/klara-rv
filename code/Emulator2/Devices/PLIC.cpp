/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>

#include "Emulator2/CPU/ICPU.h"
#include "Emulator2/Devices/PLIC.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"PLIC", PLIC, IDevice)

bool PLIC::writeU32(uint32_t address, uint32_t value)
{
	if (address == 0x00002000)
		m_enable = value >> 1;
	else if (address == 0x00200004)
	{
		if (value >= 1 && value <= 4)
		{
			value--;
			m_raised &= ~(1 << (value & 3));
			m_issued &= ~(1 << (value & 3));
		}
		else
		{
			log::error << L"[PLIC] attempt to complete unknown interrupt " << str(L"%d", value) << L"." << Endl;
		}
	}	
	else
	{
		log::error << L"[PLIC] attempt write to unknown address " << str(L"0x%08x", address) << L"." << Endl;
		return false;
	}

	return true;
}

uint32_t PLIC::readU32(uint32_t address) const
{
	if (address == 0x00200004)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (
				(m_raised & (1 << i)) != 0 &&
				(m_issued & (1 << i)) != 0
			)
			{
				return i + 1;
			}
		}
		log::info << L"[PLIC] no pending interrupts." << Endl;
		return 0;
	}
	else
	{
		log::error << L"[PLIC] attempt read from unknown address " << str(L"0x%08x", address) << L"." << Endl;
		return 0;
	}

	return 0;
}

bool PLIC::tick(ICPU* cpu, Bus* bus)
{
	for (uint32_t i = 0; i < 4; ++i)
	{
		if (
			((m_raised & (1 << i)) != 0) &&
			((m_issued & (1 << i)) == 0)
		)
		{			
			m_issued |= (1 << i);
			cpu->interrupt(EXTERNAL);
			break;
		}
	}
	return true;
}

void PLIC::raise(uint32_t channel)
{
	m_raised |= 1 << channel;
}

bool PLIC::raised(uint32_t channel) const
{
	return (m_raised & (1 << channel)) != 0;
}

bool PLIC::issued(uint32_t channel) const
{
	return (m_issued & (1 << channel)) != 0;
}

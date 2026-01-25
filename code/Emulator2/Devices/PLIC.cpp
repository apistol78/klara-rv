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

PLIC::PLIC(ICPU* cpu)
:	m_cpu(cpu)
{
}

bool PLIC::writeU32(uint32_t address, uint32_t value, uint32_t mask)
{
	if (address == 0x00002000)
		m_enable = value >> 1;
	else if (address == 0x00200004)
	{
		// Complete interrupt.
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
		// Claim pending interrupt.
		for (int i = 0; i < 4; ++i)
		{
			if ((m_raised & (1 << i)) != 0)
			{
				m_raised &= ~(1 << i);
				if (!m_raised)
					m_cpu->getInterruptPending() &= ~EXTERNAL;
				return i + 1;
			}
		}
		// Reaching here indicate something wrong
		// since should only be read when an interrupt
		// has been issued.
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

void PLIC::raise(uint32_t channel)
{
	m_raised |= 1 << channel;
	m_cpu->getInterruptPending() |= EXTERNAL;
}

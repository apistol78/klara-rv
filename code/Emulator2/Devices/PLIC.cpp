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
		m_claimed = 0;
		update();
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
		uint32_t rdata = 0;
		if (m_pending & (1 << 0))
		{
			rdata = 1;
			m_claimed = 1;
			m_pending &= ~ (1 << 0);
		}
		else if (m_pending & (1 << 1))
		{
			rdata = 2;
			m_claimed = 2;
			m_pending &= ~ (1 << 1);
		}
		else if (m_pending & (1 << 2))
		{
			rdata = 3;
			m_claimed = 3;
			m_pending &= ~ (1 << 2);
		}
		else if (m_pending & (1 << 3))
		{
			rdata = 4;
			m_claimed = 4;
			m_pending &= ~ (1 << 3);
		}
		else
			log::warning << L"[PLIC] trying to claim, but no pending" << Endl;

		if (rdata)
			update();

		return rdata;
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
	if (m_enable & (1 << channel))
	{
		m_pending |= 1 << channel;
		update();
	}
}

void PLIC::update() const
{
	if (m_pending && !m_claimed)
		m_cpu->getInterruptPending() |= EXTERNAL;
	else
		m_cpu->getInterruptPending() &= ~EXTERNAL;
}

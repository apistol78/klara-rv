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

namespace
{

std::wstring fmt(uint32_t bm)
{
	std::wstring out;
	for (uint32_t i = 0; i < 4; ++i)
		out += (bm & (1 << i)) ? L"1" : L"0";
	return out;
}

}

T_IMPLEMENT_RTTI_CLASS(L"PLIC", PLIC, IDevice)

bool PLIC::writeU32(uint32_t address, uint32_t value)
{
	if (address == 0x00002000)
		m_enable = value >> 1;
	else if (address == 0x00200004)
	{
		if (value > 0)
		{
			value--;
			m_raised &= ~(1 << (value & 3));
			m_issued &= ~(1 << (value & 3));
			//log::info << L"[PLIC] Complete context " << value << L" : " << fmt(m_raised) << L" / " << fmt(m_issued) << Endl;
		}
	}	
	return true;
}

uint32_t PLIC::readU32(uint32_t address) const
{
	if (address == 0x00200004)
	{
		for (int i = 0; i < 4; ++i)
		{
			if ((m_raised & (1 << i)) != 0)
			{
				//log::info << L"[PLIC] Claim context " << i << Endl;
				return i + 1;
			}
		}
		//log::info << L"[PLIC] Claim context none" << Endl;
	}
	return 0;
}

bool PLIC::tick(ICPU* cpu)
{
	bool issueInterrupt = false;
	for (uint32_t i = 0; i < 4; ++i)
	{
		if (
			((m_raised & (1 << i)) != 0) &&
			((m_issued & (1 << i)) == 0)
		)
		{			
			issueInterrupt = true;
			m_issued |= (1 << i);
			break;
		}
	}

	if (issueInterrupt)
	{
		//log::info << L"[PLIC] Issue interrupt : " << fmt(m_raised) << L" / " << fmt(m_issued) << Endl;
		cpu->interrupt(EXTERNAL);
	}

	return true;
}

void PLIC::raise(uint32_t channel)
{
	m_raised |= 1 << channel;
	log::info << L"[PLIC] Interrupt raised " << channel << L" : " << fmt(m_raised) << L" / " << fmt(m_issued) << Endl;
}

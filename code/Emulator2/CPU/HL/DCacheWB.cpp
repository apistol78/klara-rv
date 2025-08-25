/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>
#include "Emulator2/CPU/Bus.h"
#include "Emulator2/CPU/HL/DCacheWB.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"DCacheWB", DCacheWB, Object)

DCacheWB::DCacheWB(Bus* bus)
:	m_bus(bus)
{
}

DCacheWB::~DCacheWB()
{
	//log::info << L"DCacheWB transactions/stalls " << m_transactions << L"/" << m_stalls << Endl;
}

void DCacheWB::writeU32(uint32_t address, uint32_t value)
{
	if (m_dirty[m_count])
	{
		m_bus->writeU32(m_address[m_count], m_word[m_count]);
		m_stalls++;
	}

	m_address[m_count] = address;
	m_word[m_count] = value;
	m_dirty[m_count] = true;
	m_count = (m_count + 1) & 3;

	m_transactions++;
}

uint32_t DCacheWB::readU32(uint32_t address)
{
	bool stalled = false;
	for (int32_t i = 0; i < 4; ++i)
	{
		if (m_dirty[i])
		{
			m_bus->writeU32(m_address[i], m_word[i]);
			m_dirty[i] = false;
			stalled = true;
		}
	}
	if (stalled)
		m_stalls++;

	return m_bus->readU32(address);
}

void DCacheWB::process()
{
	for (int32_t i = 0; i < 4; ++i)
	{
		if (m_dirty[i])
		{
			m_bus->writeU32(m_address[i], m_word[i]);
			m_dirty[i] = false;
			break;
		}
	}
}

void DCacheWB::flush()
{
	for (int32_t i = 0; i < 4; ++i)
	{
		if (m_dirty[i])
		{
			m_bus->writeU32(m_address[i], m_word[i]);
			m_dirty[i] = false;
		}
	}	
}
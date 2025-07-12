/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>
#include "Emulator/CPU/DCacheWB.h"
#include "Emulator/CPU/Bus.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"DCacheWB", DCacheWB, Object)

DCacheWB::DCacheWB(Bus* bus)
:	m_bus(bus)
{
}

DCacheWB::~DCacheWB()
{
	log::info << L"DCacheWB transactions/stalls " << m_transactions << L"/" << m_stalls << Endl;
}

void DCacheWB::writeU32(uint32_t address, uint32_t value)
{
	if (m_dirty)
	{
		m_bus->writeU32(m_address, m_word);
		m_stalls++;
	}

	m_address = address;
	m_word = value;
	m_dirty = true;
	m_transactions++;
}

uint32_t DCacheWB::readU32(uint32_t address)
{
	if (m_dirty)
	{
		m_bus->writeU32(m_address, m_word);
		m_stalls++;
		m_dirty = false;
	}

	return m_bus->readU32(address);
}

void DCacheWB::process()
{
	if (m_dirty)
	{
		m_bus->writeU32(m_address, m_word);
		m_dirty = false;
	}
}

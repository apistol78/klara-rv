/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>
#include "Emulator/CPU/DCache.h"
#include "Emulator/CPU/DCacheWB.h"
#include "Emulator/CPU/Bus.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"DCache", DCache, Object)

DCache::DCache(Bus* bus)
:	m_bus(bus)
,	m_wb(new DCacheWB(bus))
{
    for (uint32_t i = 0; i < c_nlines; ++i)
	{
        m_data[i].valid = false;
		m_data[i].dirty = false;
	}
}

DCache::~DCache()
{
	log::info << L"DCache " << m_hits << L"/" << m_misses << L" (" << str(L"%.2f%%", (m_hits * 100.0) / (m_hits + m_misses)) << L")" << Endl;
}

void DCache::writeU32(uint32_t address, uint32_t value)
{
	if (m_bus->cacheable(address))
	{
		const uint32_t tag = (address >> 2) & (c_nlines - 1);
		Line& line = m_data[tag];

		if (line.address != address && line.valid && line.dirty)
		{
			// Need to evict line which contain dirty data.
			m_wb->writeU32(line.address, line.word);
		}

		line.address = address;
		line.word = value;
		line.valid = true;
		line.dirty = true;
	}
	else
		m_wb->writeU32(address, value);
}

uint32_t DCache::readU32(uint32_t address)
{
	if (m_bus->cacheable(address))
	{
		const uint32_t tag = (address >> 2) & (c_nlines - 1);
		Line& line = m_data[tag];

		if (line.valid && line.address == address)
		{
			m_hits++;
			return line.word;
		}

		if (/*line.address != address && */ line.valid && line.dirty)
		{
			// Need to evict line which contain dirty data.
			m_wb->writeU32(line.address, line.word);
		}

		const uint32_t word = m_wb->readU32(address);

		line.address = address;
		line.word = word;
		line.valid = true;
		line.dirty = false;

		m_misses++;
	    return word;
	}
	else
		return m_wb->readU32(address);
}

void DCache::processWriteQueue()
{
	m_wb->process();
}

void DCache::flush()
{
    for (uint32_t i = 0; i < c_nlines; ++i)
	{
		Line& line = m_data[i];
		if (line.valid && line.dirty)
		{
			m_wb->writeU32(line.address, line.word);
			line.dirty = false;
		}
	}
}

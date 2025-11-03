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
#include "Emulator2/CPU/HL/DCache.h"

//#define DCACHE_LOG_STAT

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"DCache", DCache, Object)

DCache::DCache(Bus* bus)
:	m_bus(bus)
{
    for (uint32_t i = 0; i < c_nlines; ++i)
	{
        m_data[i].mask = 0;
		m_data[i].dirty = false;
	}
}

DCache::~DCache()
{
#if defined(DCACHE_LOG_STAT)
	log::info << L"DCache " << m_hits << L"/" << m_misses << L" (" << str(L"%.2f%%", (m_hits * 100.0) / (m_hits + m_misses)) << L")" << Endl;
#endif
}

void DCache::writeU32(uint32_t address, uint32_t value, uint32_t mask)
{
	if (m_bus->cacheable(address))
	{
		const uint32_t tag = (address >> 2) & (c_nlines - 1);
		Line& line = m_data[tag];

		if (line.address != address && line.mask && line.dirty)
		{
			// Need to evict line which contain dirty data.
			m_bus->writeU32(line.address, line.word, line.mask);
		}

		if  (address == line.address)
		{
			line.word = (line.word & ~mask) | (value & mask);
			line.mask = line.mask | mask;
		}
		else
		{
			line.word = value;
			line.mask = mask;
		}
		line.address = address;
		line.dirty = true;
	}
	else
		m_bus->writeU32(address, value, mask);
}

uint32_t DCache::readU32(uint32_t address)
{
	if (m_bus->cacheable(address))
	{
		const uint32_t tag = (address >> 2) & (c_nlines - 1);
		Line& line = m_data[tag];

		if (line.mask == 0xffffffff && line.address == address)
		{
			m_hits++;
			return line.word;
		}

		if (/*line.address != address && */ line.mask && line.dirty)
		{
			// Need to evict line which contain dirty data.
			m_bus->writeU32(line.address, line.word, line.mask);
		}

		const uint32_t word = m_bus->readU32(address);

		line.address = address;
		line.word = word;
		line.mask = 0xffffffff;
		line.dirty = false;

		m_misses++;
	    return word;
	}
	else
		return m_bus->readU32(address);
}

void DCache::flush()
{
    for (uint32_t i = 0; i < c_nlines; ++i)
	{
		Line& line = m_data[i];
		if (line.mask && line.dirty)
		{
			m_bus->writeU32(line.address, line.word, line.mask);
			line.mask = 0;
			line.dirty = false;
		}
	}
}

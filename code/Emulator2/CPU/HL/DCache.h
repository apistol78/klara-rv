/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Object.h>
#include <Core/Ref.h>

class Bus;
class DCacheWB;

class DCache : public traktor::Object
{
	T_RTTI_CLASS;

public:
	explicit DCache(Bus* bus);

	virtual ~DCache();

	void writeU32(uint32_t address, uint32_t value);

	uint32_t readU32(uint32_t address);

	void processWriteQueue();

	void flush();

private:
	struct Line
	{
		uint32_t address;
		uint32_t word;
		bool valid;
		bool dirty;
	};

	constexpr static uint32_t c_nlines = 1 << 19;

	traktor::Ref< Bus > m_bus;
	traktor::Ref< DCacheWB > m_wb;
	Line m_data[c_nlines];
	uint64_t m_hits = 0;
	uint64_t m_misses = 0;
};

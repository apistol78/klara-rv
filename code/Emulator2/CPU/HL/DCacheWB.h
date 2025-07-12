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

class DCacheWB : public traktor::Object
{
	T_RTTI_CLASS;

public:
	explicit DCacheWB(Bus* bus);

	virtual ~DCacheWB();

	void writeU32(uint32_t address, uint32_t value);

	uint32_t readU32(uint32_t address);

	void process();

private:
	traktor::Ref< Bus > m_bus;
	uint32_t m_address;
	uint32_t m_word;
	bool m_dirty = false;
	uint64_t m_stalls = 0;
	uint64_t m_transactions = 0;
};

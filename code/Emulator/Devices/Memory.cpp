/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <cstring>
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>
#include "Emulator/Devices/Memory.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"Memory", Memory, IDevice)

Memory::Memory(uint32_t capacity)
:	m_capacity(capacity)
{
	m_data.reset(new uint8_t [capacity]);

	// Ensure memory content is randomized initially
	// so we can capture uninitialized access.
	for (uint32_t i = 0; i < capacity; ++i)
		m_data[i] = (uint8_t)rand();
}

uint32_t Memory::getCapacity() const
{
	return m_capacity;
}

void Memory::setReadOnly(bool readOnly)
{
	m_readOnly = readOnly;
}

bool Memory::writeU32(uint32_t address, uint32_t value)
{
	if (address >= m_capacity)
	{
		log::error << L"Trying to write " << str(L"%08x", value) << L" to memory at 0x" << str(L"%08x", address) << L", out of bounds!" << Endl;
		return false;
	}

	if (!m_readOnly)
	{
		*(uint32_t*)(m_data.c_ptr() + address) = value;
		return true;
	}
	else
	{
		log::error << L"Trying to write " << str(L"%08x", value) << L" to read-only memory at 0x" << str(L"%08x", address) << Endl;
		return false;
	}
}

uint32_t Memory::readU32(uint32_t address) const
{
	if (address >= m_capacity)
	{
		log::error << L"Trying to read from memory at 0x" << str(L"%08x", address) << L", out of bounds!" << Endl;
		return 0;
	}

	return *(const uint32_t*)(m_data.c_ptr() + address);
}

bool Memory::tick(CPU* cpu)
{
	return true;
}
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
#include "Emulator2/Devices/DMA.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"DMA", DMA, IDevice)

bool DMA::writeU32(uint32_t address, uint32_t value)
{
	if (address == 0)
		m_from = value & ~3U;
	else if (address == 4)
		m_to = value & ~3U;
	else if (address == 8)
		m_count = value;
	else if (address == 12)
	{
		if (!m_tasks.full())
		{
			m_tasks.push_back({
				.from = m_from,
				.to = m_to,
				.count = m_count,
				.run = value,
				.tag = m_queued + 1
			});
			m_queued++;
		}
		else
			log::warning << L"[DMA] DMA command fifo full!" << Endl;
	}
	return true;
}

uint32_t DMA::readU32(uint32_t address) const
{
	if (address == 0)
		return m_queued;
	else if (address == 4)
		return m_retired;
	else if (address == 12)
		return (!m_tasks.empty()) ? 1 : 0;
	else
		return 0;
}

bool DMA::tick(ICPU* cpu, Bus* bus)
{
	if (m_tasks.empty())
		return true;

	Task& task = m_tasks.front();

	if (task.run == 1)
	{
		if (task.count > 0)
		{
			const uint32_t value = task.from;
			bus->writeU32(task.to, value);
			task.to += 4;
			task.count--;
		}
	}
	else if (task.run == 2)
	{
		if (task.count > 0)
		{
			const uint32_t value = bus->readU32(task.from);
			bus->writeU32(task.to, value);
			task.to += 4;
			task.from += 4;
			task.count--;
		}
	}
	else if (task.run == 3)
	{
		if (task.count > 0)
		{
			const uint32_t value = bus->readU32(task.from);
			bus->writeU32(task.to, value);
			task.from += 4;
			task.count--;
		}
	}

	if (task.count == 0)
	{
		m_retired = task.tag;
		m_tasks.pop_front();
	}
	
	return true;
}

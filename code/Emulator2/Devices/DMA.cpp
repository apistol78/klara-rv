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
		m_from = value;
	else if (address == 4)
		m_to = value;
	else if (address == 16)
		m_pitch = value;
	else if (address == 20)
		m_width = value;
	else if (address == 8)
		m_count = value;
	else if (address == 12)
	{
		if (!m_tasks.full())
		{
			m_tasks.push_back({
				.from = m_from,
				.to = m_to,
				.pitch = m_pitch,
				.width = m_width,
				.count = m_count,
				.offset = 0,
				.run = value,
				.tag = m_queued + 1
			});
			m_queued++;
		}
		else
			log::warning << L"[DMA] DMA command fifo full!" << Endl;
	}
	else
	{
		log::error << L"[DMA] attempt write to unknown address " << str(L"0x%08x", address) << L"." << Endl;
		return false;
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

	if (task.count > 0)
	{
		if (task.run == 1)
		{
			const uint32_t value = task.from;
			bus->writeU32(task.to, value);
			task.to += 4;
			task.count--;
		}
		else if (task.run == 2)
		{
			const uint32_t value = bus->readU32(task.from);
			bus->writeU32(task.to, value);
			task.to += 4;
			task.from += 4;
			task.count--;
		}
		else if (task.run == 3)
		{
			const uint32_t value = bus->readU32(task.from);
			bus->writeU32(task.to, value);
			task.from += 4;
			task.count--;
		}
		else if (task.run == 4)
		{
			const uint32_t value = bus->readU32(task.from);
			
			const uint32_t wo = (task.to + task.offset) & ~3U;
			uint32_t tl = bus->readU32(wo);
			uint32_t th = bus->readU32(wo + 4);

			switch (task.to & 3U)
			{
			case 0:
				tl = value;
				break;

			case 3:
				th = (th & 0xff000000) | (value >> 8);
				tl = (tl & 0x00ffffff) | ((value & 0x000000ff) << 24);
				break;

			case 2:
				th = (th & 0xffff0000) | (value >> 16);
				tl = (tl & 0x0000ffff) | ((value & 0x0000ffff) << 16);
				break;

			case 1:
				th = (th & 0xffffff00) | (value >> 24);
				tl = (tl & 0x000000ff) | ((value & 0x00ffffff) << 8);
				break;
			}

			bus->writeU32(wo, tl);
			bus->writeU32(wo + 4, th);

			task.from += 4;
			task.offset += 4;
			if (task.offset >= task.width)
			{
				task.offset = 0;
				task.to += task.pitch;
				task.count--;
			}
		}
	}

	if (task.count == 0)
	{
		m_retired = task.tag;
		m_tasks.pop_front();
	}
	
	return true;
}

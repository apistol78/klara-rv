/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Log/Log.h>

#include "Emulator2/Devices/Sprite.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"Sprite", Sprite, IDevice)

bool Sprite::writeU32(uint32_t address, uint32_t value)
{
	if (address < 0x4000)
	{
		// Write to registers.
		switch (address >> 2)
		{
		case 0:
			m_data[0].x = *(int32_t*)&value;
			break;
		case 1:
			m_data[0].y = *(int32_t*)&value;
			break;
		case 2:
			m_data[0].visible = (value != 0);
			break;
		case 4:
			m_data[1].x = *(int32_t*)&value;
			break;
		case 5:
			m_data[1].y = *(int32_t*)&value;
			break;
		case 6:
			m_data[1].visible = (value != 0);
			break;
		default:
			// log::error << L"[Sprite] attempt write to unknown address " << tk::str(L"0x%08x", address) << L"." << tk::Endl;
			return true;
		}
	}
	else
	{
		// Write to data.
		const uint32_t index = (address - 0x4000) / 0x4000;
		Data& data = m_data[index];

		const uint32_t offset = (address & 0x3fff) >> 2;
		if (offset < 64 * 64)
			data.bits[offset] = (uint8_t)value;
	}
	return true;
}

uint32_t Sprite::readU32(uint32_t address) const
{
	return 0;
}

bool Sprite::tick(ICPU* cpu, Bus* bus)
{
	return true;
}

bool Sprite::getOverlay(uint32_t x, uint32_t y, uint8_t& outOverlay) const
{
	for (int32_t i = 0; i < sizeof_array(m_data); ++i)
	{
		const Data& data = m_data[i];
		if (
            data.visible &&
			x >= data.x && x < data.x + 64 &&
			y >= data.y && y < data.y + 64
		)
		{
			const uint32_t offset = (x - data.x) + (y - data.y) * 64;
			outOverlay = data.bits[offset];
			return (outOverlay != 0xff);
		}
	}
	return false;
}

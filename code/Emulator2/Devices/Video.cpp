/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <cstdio>

#include <Core/Log/Log.h>
#include <Core/Misc/Endian.h>
#include <Core/Misc/String.h>
#include <Core/Thread/Thread.h>
#include <Core/Thread/ThreadManager.h>
#include <Drawing/Image.h>
#include <Drawing/PixelFormat.h>

#include "Emulator2/Devices/Video.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"Video", Video, IDevice)

Video::Video(uint32_t displayWidth, uint32_t displayHeight)
:	m_displayWidth(displayWidth)
,	m_displayHeight(displayHeight)
{
	m_framebuffer.resize(displayWidth * displayHeight * 2);
	m_image = new drawing::Image(
		drawing::PixelFormat::getX8R8G8B8(),
		displayWidth,
		displayHeight
	);
	m_image->clear(Color4f(0.0f, 0.0f, 0.0f, 0.0f));
}

bool Video::writeU32(uint32_t address, uint32_t value)
{
	if ((address & 0x00f00000) == 0x00f00000)
	{
		if ((address & 0xff) == 0)
		{
			m_readOffset = value;
		}
		else if ((address & 0xff) == 4)
		{
			m_pitch = value;
		}
		else if ((address & 0xff) == 8)
		{
			m_skip = value;
		}
		else if ((address & 0xff) == 12)
		{
			m_skipH = value;
		}
		else if ((address & 0xff) == 16)
		{
			m_skipV = value;
		}
	}
	else if ((address & 0x00f00000) == 0x00e00000)
	{
		const uint32_t idx = (address >> 2) & 255;
		m_palette[idx] = value;
	}
	else
	{
		if (address < m_framebuffer.size())
			*(uint32_t*)&m_framebuffer[address] = value;
	}
	return true;
}

uint32_t Video::readU32(uint32_t address) const
{
	if (address < m_framebuffer.size())
		return *(uint32_t*)&m_framebuffer[address];
	else
		return 0;
}

bool Video::tick(ICPU* cpu)
{
	return true;
}

drawing::Image* Video::getImage()
{
	uint32_t* dst = (uint32_t*)m_image->getData();
	const uint32_t offset = m_readOffset;

	uint32_t vy = 0;
	for (uint32_t y = 0; y < m_displayHeight; ++y)
	{
		if (y >= m_skipV && y < m_displayHeight - m_skipV)
		{
			uint32_t vx = 0;
			for (uint32_t x = 0; x < m_displayWidth; ++x)
			{
				if (x >= m_skipH && x < m_displayWidth - m_skipH)
				{
					const uint32_t rvx = vx >> ((m_skip & 1) ? 1 : 0);
					const uint32_t rvy = vy >> ((m_skip & 2) ? 1 : 0);

					const uint8_t value = m_framebuffer[offset + rvx + rvy * m_pitch];
					*dst++ = m_palette[value];
				
					vx++;
				}
				else
					dst++;
			}
			vy++;
		}
		else
			dst += m_displayWidth;
	}

	return m_image;
}

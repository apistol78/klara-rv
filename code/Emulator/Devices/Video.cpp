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
#include "Emulator/Devices/Video.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"Video", Video, IDevice)

Video::Video(uint32_t width, uint32_t height)
:	m_width(width)
,	m_height(height)
{
	m_framebuffer.resize(width * height * 2);
}

bool Video::writeU32(uint32_t address, uint32_t value)
{
	if ((address & 0x00f00000) == 0x00f00000)
	{
		if ((address & 0xf) == 0x0)
			m_readOffset = value;
		else if ((address & 0xf) == 0x4)
		{
			m_width = value;
			m_image = nullptr;
		}
		else if ((address & 0xf) == 0x8)
		{
			m_skip = value;
			m_image = nullptr;
		}
	}
	else if ((address & 0x00f00000) == 0x00e00000)
	{
		swap8in32(value);
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

bool Video::tick(CPU* cpu)
{
	return true;
}

drawing::Image* Video::getImage()
{
	const uint32_t w = (m_skip & 0b01) ? (m_width >> 1) : m_width;
	const uint32_t h = (m_skip & 0b10) ? (m_height >> 1) : m_height;

	if (!m_image)
	{
		m_image = new drawing::Image(
			drawing::PixelFormat::getX8R8G8B8(),
			w,
			h
		);
	}

	uint32_t* dst = (uint32_t*)m_image->getData();
	uint32_t offset = m_readOffset;

	for (uint32_t y = 0; y < h; ++y)
	{
		for (uint32_t x = 0; x < w; x += 4)
		{
			const uint32_t value = *(uint32_t*)&m_framebuffer[offset];

			*dst++ = m_palette[(value & 0x000000ff)];
			*dst++ = m_palette[(value & 0x0000ff00) >> 8];
			*dst++ = m_palette[(value & 0x00ff0000) >> 16];
			*dst++ = m_palette[(value & 0xff000000) >> 24];

			offset += 4;
		}
	}

	return m_image;
}

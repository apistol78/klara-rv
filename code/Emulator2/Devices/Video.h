/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Ref.h>
#include <Core/Misc/AutoPtr.h>

#include "Emulator2/CPU/IDevice.h"

namespace traktor::drawing
{

class Image;

}

class Video : public IDevice
{
	T_RTTI_CLASS;

public:
	explicit Video(uint32_t displayWidth, uint32_t displayHeight);

	virtual bool writeU32(uint32_t address, uint32_t value) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

	traktor::drawing::Image* getImage();

private:
	traktor::AlignedVector< uint8_t > m_framebuffer;
	uint32_t m_palette[256];
	uint32_t m_displayWidth = 0;
	uint32_t m_displayHeight = 0;
	uint32_t m_pitch = 0;
	uint32_t m_skip = 0b11;
	uint32_t m_skipH = 0;
	uint32_t m_skipV = 0;
	uint32_t m_usePalette = 0;
	uint32_t m_readOffset = 0;
	traktor::Ref< traktor::drawing::Image > m_image;
};
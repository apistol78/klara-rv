/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <functional>

#include <Core/Ref.h>
#include <Core/Misc/AutoPtr.h>

#include "Emulator2/CPU/IDevice.h"

namespace traktor::drawing
{

class Image;

}

class Sprite;

class Video : public IDevice
{
	T_RTTI_CLASS;

public:
	explicit Video(uint32_t displayWidth, uint32_t displayHeight);

	virtual bool tickable() const override final { return true; }

	virtual bool writeU32(uint32_t address, uint32_t value, uint32_t mask) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

	void setSprite(Sprite* sprite);

	traktor::drawing::Image* getImage();

	void setCallback(const std::function< void() >& callback);

	uint32_t getFrameCounter() const { return m_frameCounter; }

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
	uint32_t m_frameCounter = 0;
	traktor::Ref< Sprite > m_sprite;
	traktor::Ref< traktor::drawing::Image > m_image;
	std::function< void() > m_callback;
	bool m_trig = false;
};
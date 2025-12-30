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

#include "Emulator2/CPU/IDevice.h"

namespace traktor::sound
{

class AudioSystem;
class IAudioBuffer;

}

class Audio : public IDevice
{
	T_RTTI_CLASS;

public:
	Audio();

	virtual bool tickable() const override final { return true; }

	virtual bool ready(uint32_t address) const override final;

	virtual bool writeU32(uint32_t address, uint32_t value, uint32_t mask) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

	void setCallback(const std::function< void() >& callback);

private:
	traktor::Ref< traktor::sound::AudioSystem > m_audioSystem;
	traktor::Ref< traktor::sound::IAudioBuffer > m_audioBuffer;
	std::function< void() > m_callback;
	// uint32_t m_channel = 0;
	// uint32_t m_lastQ = 0;
	uint32_t m_latchAddress[16] = {};
};

/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Ref.h>
#include "Emulator/CPU/IDevice.h"

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

	virtual bool writeU32(uint32_t address, uint32_t value) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(CPU* cpu) override final;

private:
	traktor::Ref< traktor::sound::AudioSystem > m_audioSystem;
	traktor::Ref< traktor::sound::IAudioBuffer > m_audioBuffer;
	uint32_t m_channel = 0;
};

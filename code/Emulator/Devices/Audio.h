/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Ref.h>
#include <Core/Io/IStream.h>
#include "Emulator/CPU/IDevice.h"

class Audio : public IDevice
{
	T_RTTI_CLASS;

public:
	Audio();

	virtual bool writeU32(uint32_t address, uint32_t value) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(CPU* cpu) override final;

private:
	traktor::Ref< traktor::IStream > m_stream;
    uint32_t m_queued = 0;
    uint32_t m_counter = 0;
	uint32_t m_written = 0;
	uint32_t m_channel = 0;
};

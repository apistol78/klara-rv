/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Ref.h>
#include <Core/Containers/AlignedVector.h>
#include <Core/Io/IStream.h>
#include <Core/Io/ChunkMemory.h>

#include "Emulator2/CPU/IDevice.h"

class SD : public IDevice
{
	T_RTTI_CLASS;

public:
	explicit SD(traktor::IStream* source);

	explicit SD(void* data, uint32_t size);

	virtual bool writeU32(uint32_t address, uint32_t value) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

private:
	bool m_r_clk = false;
	bool m_r_cdir = false;
	bool m_r_ddir = false;
	bool m_r_cmd = false;
	uint8_t m_r_dat = 0;

	int32_t m_mode = 0;
	int32_t m_bit = 0;
	int32_t m_data = 0;
	bool m_lstclk = true;
	bool m_lstcmd = false;
	traktor::AlignedVector< uint8_t > m_cmd;
	uint8_t m_response[1024];
	int32_t m_send = 0;
	int32_t m_rspcnt = 0;
	int32_t m_rspbit = 0;
	int32_t m_blockOutputCount = 0;
	int32_t m_dly = 0;
	uint8_t m_block[512];
	traktor::Ref< traktor::IStream > m_stream;
	traktor::Ref< traktor::ChunkMemory > m_memory;

	void process();
};

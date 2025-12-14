/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <functional>

#include <Core/Containers/CircularVector.h>

#include "Emulator2/CPU/IDevice.h"

class DMA : public IDevice
{
	T_RTTI_CLASS;

public:
	virtual bool writeU32(uint32_t address, uint32_t value, uint32_t mask) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

	void setCallback(const std::function< void() >& callback);

private:
	struct Task
	{
		uint32_t from = 0;
		uint32_t to = 0;
		uint32_t pitch = 0;
		uint32_t width = 0;
		uint32_t count = 0;
		uint32_t offset = 0;
		uint32_t run = 0;
		uint32_t tag = 0;
	};

	traktor::CircularVector< Task, 64 > m_tasks;
	uint32_t m_queued = 0;
	uint32_t m_retired = 0;
	std::function< void() > m_callback;

	uint32_t m_from;
	uint32_t m_to;
	uint32_t m_pitch;
	uint32_t m_width;
	uint32_t m_count;
};

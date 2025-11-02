/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <functional>

#include <Core/Timer/Timer.h>

#include "Emulator2/CPU/IDevice.h"

class Timer : public IDevice
{
	T_RTTI_CLASS;

public:
	Timer();

	virtual bool writeU32(uint32_t address, uint32_t value) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

	void setCallback(const std::function< void() >& callback);

	uint64_t getCycles() const { return m_cycles; }

	uint64_t getCompare() const { return m_compare; }

	uint32_t getCountDown() const { return m_countdown; }

private:
	traktor::Timer m_timer;
	uint64_t m_cycles = 0;
	uint64_t m_compare = 0;
	uint32_t m_countdown = 0;
	std::function< void() > m_callback;
};
/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include "Emulator2/CPU/IDevice.h"

class PLIC : public IDevice
{
	T_RTTI_CLASS;

public:
	explicit PLIC(ICPU* cpu);

	virtual bool tickable() const override final { return false; }

	virtual bool writeU32(uint32_t address, uint32_t value, uint32_t mask) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final { return true; }

	void raise(uint32_t channel);

private:
	ICPU* m_cpu = nullptr;
	uint32_t m_enable = 0;
	mutable uint32_t m_raised = 0;
};

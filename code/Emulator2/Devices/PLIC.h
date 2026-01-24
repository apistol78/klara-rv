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
	virtual bool tickable() const override final { return true; }

	virtual bool writeU32(uint32_t address, uint32_t value, uint32_t mask) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

	void raise(uint32_t channel);

private:
	uint32_t m_enable = 0;
	mutable uint32_t m_raised = 0;
};

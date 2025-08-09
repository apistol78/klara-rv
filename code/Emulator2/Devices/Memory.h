/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Misc/AutoPtr.h>

#include "Emulator2/CPU/IDevice.h"

class Memory : public IDevice
{
	T_RTTI_CLASS;

public:
	explicit Memory(uint32_t capacity);

	uint32_t getCapacity() const;

	void setReadOnly(bool readOnly);

	virtual bool writeU32(uint32_t address, uint32_t value) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

private:
	traktor::AutoArrayPtr< uint8_t > m_data;
	uint32_t m_capacity;
	bool m_readOnly = false;
};
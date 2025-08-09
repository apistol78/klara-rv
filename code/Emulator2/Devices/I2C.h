/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Ref.h>
#include <Core/Containers/CircularVector.h>
#include <Core/Containers/SmallMap.h>

#include "Emulator2/CPU/IDevice.h"

class I2C : public IDevice
{
	T_RTTI_CLASS;

public:
	class ISlave : public Object
	{
		T_RTTI_CLASS;

	public:
		virtual void write(uint8_t controlAddr, uint8_t data) = 0;

		virtual void read(uint8_t controlAddr, uint8_t length, uint8_t* outData) = 0;

		virtual bool tick(ICPU* cpu) = 0;
	};

	virtual bool writeU32(uint32_t address, uint32_t value) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

	void addSlave(uint8_t address, ISlave* slave);

private:
    traktor::SmallMap< uint8_t, traktor::Ref< ISlave > > m_slaves;
	mutable traktor::CircularVector< uint8_t, 256 > m_data;
};
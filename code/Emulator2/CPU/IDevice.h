/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Object.h>

class Bus;
class ICPU;

class IDevice : public traktor::Object
{
	T_RTTI_CLASS;

public:
	virtual bool tickable() const { return false; }

	virtual bool cacheable() const { return false; }

	virtual bool ready(uint32_t address) const { return true; }

	virtual bool writeU32(uint32_t address, uint32_t value, uint32_t mask) = 0;

	virtual uint32_t readU32(uint32_t address) const = 0;

	virtual bool tick(ICPU* cpu, Bus* bus) = 0;
};

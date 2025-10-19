/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Object.h>

enum CSR
{
	MSTATUS = 0x300,
	MIE = 0x304,
	MTVEC = 0x305,
	MSCRATCH = 0x340,
	MEPC = 0x341,
	MCAUSE = 0x342,
	MIP = 0x344
};

enum InterruptMask
{
	TIMER = 1,
	EXTERNAL = 2,
	SOFT = 4
};

class ICPU : public traktor::Object
{
	T_RTTI_CLASS;

public:
	virtual bool tick(uint32_t count) = 0;

	virtual void interrupt(uint32_t mask) = 0;

	virtual void flushCaches() = 0;

	virtual void setPC(uint32_t value) = 0;

	virtual uint32_t getPC() const = 0;

	virtual void setRegister(uint32_t index, uint32_t value) = 0;

	virtual uint32_t getRegister(uint32_t index) const = 0;

	virtual uint32_t getCSR(uint16_t csr) const = 0;

	// Convenience

	void jump(uint32_t address) { setPC(address); }

	void setSP(uint32_t sp) { setRegister(2, sp); }
};
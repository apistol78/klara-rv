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
	MEPC = 0x341,
	MCAUSE = 0x342
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
	virtual void jump(uint32_t address) = 0;

	virtual void setSP(uint32_t sp) = 0;

	virtual bool tick(uint32_t count) = 0;

	virtual void interrupt(uint32_t mask) = 0;

	// void reset();
};
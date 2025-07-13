/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include "Emulator2/CPU/ICPU.h"

class Bus;
class VCPU_top;
class VerilatedFstC;

class CPU_gate : public ICPU
{
	T_RTTI_CLASS;

public:
	explicit CPU_gate(Bus* bus, const char* trace);

	virtual ~CPU_gate();

	virtual void jump(uint32_t address) override final;

	virtual void setSP(uint32_t sp) override final;

	virtual bool tick(uint32_t count) override final;

	virtual void interrupt(uint32_t mask) override final;

	virtual uint32_t getPC() const override final;

	virtual uint32_t getRegister(uint32_t index) const override final;

private:
	traktor::Ref< Bus > m_bus;
	VCPU_top* m_tb = nullptr;
	VerilatedFstC* m_tfp = nullptr;
	int32_t m_time = 0;
	uint32_t m_interrupt = 0;
    bool m_lastBusRequest = false;
};

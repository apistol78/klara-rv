/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Ref.h>
#include <Core/Timer/Timer.h>

#include "Emulator2/CPU/ICPU.h"

namespace traktor
{

class OutputStream;

}

class Bus;
class BusAccess;
class DCache;
class ICache;

class CPU_hl : public ICPU
{
	T_RTTI_CLASS;

public:
	explicit CPU_hl(Bus* bus, traktor::OutputStream* trace, bool twoWayICache);

	virtual void jump(uint32_t address) override final;

	virtual void setSP(uint32_t sp) override final;

	virtual bool tick(uint32_t count) override final;

	virtual void interrupt(uint32_t mask) override final;

	void reset();

	void push(uint32_t value);

	uint32_t pc() const { return m_pc; }

	uint32_t sp() const { return m_registers[2]; }

	uint32_t reg(uint32_t index) { return m_registers[index]; }

private:
	traktor::Ref< Bus > m_bus;
	traktor::Ref< BusAccess > m_busAccess;
	traktor::Ref< DCache > m_dcache;
	traktor::Ref< ICache > m_icache;
	traktor::Ref< traktor::OutputStream > m_trace;
	traktor::Timer m_timer;
	uint32_t m_pc;
	uint32_t m_next;
	uint32_t m_registers[32];
	float m_flt_registers[32];
	uint32_t m_csr[4096];
	uint32_t m_interrupt;
	uint64_t m_cycles;
	bool m_waitForInterrupt;

	bool decode(uint32_t word);

	void ecall();

	uint32_t readCSR(uint16_t csr) const;

	void writeCSR(uint16_t csr, uint32_t value);

	void returnFromInterrupt();

	void flushCaches();
};
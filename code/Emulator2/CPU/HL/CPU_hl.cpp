/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Io/OutputStream.h>
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>

#include "Emulator2/CPU/Bus.h"
#include "Emulator2/CPU/Helpers.h"
#include "Emulator2/CPU/HL/BusAccess.h"
#include "Emulator2/CPU/HL/CPU_hl.h"
#include "Emulator2/CPU/HL/DCache.h"
#include "Emulator2/CPU/HL/ICache1W.h"
#include "Emulator2/CPU/HL/ICache2W.h"

using namespace traktor;

namespace
{

struct FormatCSR
{
	uint32_t rd;
	uint32_t rs1;
	uint16_t csr;

	inline static FormatCSR parse(uint32_t word)
	{
		return FormatCSR {
			(word >> 7) & 0x1f,
			(word >> 15) & 0x1f,
			(uint16_t)((word >> 20) & 0xfff)
		};
	}
};

struct FormatI
{
	uint32_t rd;
	uint32_t rs1;
	int32_t imm;

	inline static FormatI parse(uint32_t word)
	{
		FormatI f = {
			(word >> 7) & 0x1f,
			(word >> 15) & 0x1f,
			(int32_t)((word >> 20) & 0x000007ff)
		};

		if ((word & 0x80000000) == 0x80000000)
			f.imm |= 0xfffff800;
		
		return f;
	}
};

struct FormatJ
{
	uint32_t rd;
	int32_t imm;

	inline static FormatJ parse(uint32_t word)
	{
		FormatJ f = {
			(word >> 7) & 0x1f,
			(int32_t)((word & 0x000ff000) | ((word & 0x00100000) >> 9) | ((word & 0x7fe00000) >> 20))
		};

		if ((word & 0x80000000) == 0x80000000)
			f.imm |= 0xfff00000;
		
		return f;
	}
};

struct FormatR
{
	uint32_t rd;
	uint32_t rs1;
	uint32_t rs2;

	inline static FormatR parse(uint32_t word)
	{
		return FormatR {
			(word >> 7) & 0x1f,
			(word >> 15) & 0x1f,
			(word >> 20) & 0x1f
		};
	}
};

struct FormatS
{
	uint32_t rs1;
	uint32_t rs2;
	int32_t imm;

	inline static FormatS parse(uint32_t word)
	{
		FormatS f = {
			(word >> 15) & 0x1f,
			(word >> 20) & 0x1f,
			(int32_t)(((word >> 20) & 0xfe0) | ((word >> 7) & 0x1f))
		};

		if ((word & 0x80000000) == 0x80000000)
			f.imm |= 0xfffff000;
		
		return f;
	}
};

struct FormatB
{
	uint32_t rs1;
	uint32_t rs2;
	int32_t imm;

	inline static FormatB parse(uint32_t word)
	{
		FormatB f = {
			(word >> 15) & 0x1f,
			(word >> 20) & 0x1f,
			(int32_t)(((word << 4) & 0x00000800) | ((word >> 20) & 0x000007e0) | ((word >> 7) & 0x0000001e))
		};

		if ((word & 0x80000000) == 0x80000000)
			f.imm |= 0xfffff000;
		
		return f;
	}
};

struct FormatU
{
	uint32_t rd;
	int32_t imm;

	inline static FormatU parse(uint32_t word)
	{
		const FormatU f = {
			(word >> 7) & 0x1f,
			(int32_t)(word & 0xfffff000)
		};
		// check this!
		return f;
	}
};

struct FormatR4
{
	uint32_t rd;
	uint32_t rs1;
	uint32_t rs2;
	uint32_t rs3;

	inline static FormatR4 parse(uint32_t word)
	{
		return FormatR4 {
			(word >> 7) & 0x1f,
			(word >> 15) & 0x1f,
			(word >> 20) & 0x1f,
			(word >> 27) & 0x1f
		};
	}
};

#define PC m_pc
#define PC_NEXT m_next

#define R(x) m_registers[x]
#define R_s(x) (int32_t&)m_registers[x]
#define R_u(x) (uint32_t&)m_registers[x]

// #define FR(x) m_flt_registers[x]
// #define FR_u(x) (uint32_t&)m_flt_registers[x]
#define FR(x) (float&)m_registers[x]
#define FR_u(x) (uint32_t&)m_registers[x]

#define MEM_RD(addr) m_busAccess->readU32(m_pc, addr)
#define MEM_WR(addr, value) m_busAccess->writeU32(m_pc, addr, value)

#define MEM_RD_U16(addr) m_busAccess->readU16(m_pc, addr)
#define MEM_WR_U16(addr, value) m_busAccess->writeU16(m_pc, addr, value)

#define MEM_RD_U8(addr) m_busAccess->readU8(m_pc, addr);
#define MEM_WR_U8(addr, value) m_busAccess->writeU8(m_pc, addr, value)

#define TRACE(s) // if (m_trace) { *m_trace << s << Endl; }

}

T_IMPLEMENT_RTTI_CLASS(L"CPU_hl", CPU_hl, ICPU)

CPU_hl::CPU_hl(Bus* bus, OutputStream* trace, bool twoWayICache)
:   m_bus(bus)
,	m_trace(trace)
,   m_pc(0x00000000)
,	m_retiredPC(0x00000000)
,	m_waitForInterrupt(false)
,	m_cycles(0)
{
	m_dcache = new DCache(bus);

	if (twoWayICache)
		m_icache = new ICache2W(bus);
	else
		m_icache = new ICache1W(bus);

	m_busAccess = new BusAccess(m_dcache);

	for (uint32_t i = 0; i < sizeof_array(m_registers); ++i)
		m_registers[i] = 0x00000000;

	m_registers[2] = 0x00000000;

	for (uint32_t i = 0; i < sizeof_array(m_csr); ++i)
		m_csr[i] = 0x00000000;

	writeCSR(CSR::MSTATUS, 0x8);

	m_timer.reset();
}

bool CPU_hl::tick(uint32_t count)
{
	// Check if CPU in low power mode and
	// are waiting for interrupt.
	if (m_waitForInterrupt && readCSR(CSR::MIP) == 0 && m_pending == 0)
		return true;

	for (uint32_t i = 0; i < count; ++i)
	{
		// Latch pending interrupts.
		const uint32_t mie = (m_csr[CSR::MIE] & 0x888);
		if ((mie & 0x8) != 0 && (m_pending & SOFT) != 0)
			m_csr[CSR::MIP] |= 0x8;
		if ((mie & 0x80) != 0 && (m_pending & TIMER) != 0)
		{
			m_csr[CSR::MIP] |= 0x80;
			m_pending &= ~TIMER;
		}
		if ((mie & 0x800) != 0 && (m_pending & EXTERNAL) != 0)
			m_csr[CSR::MIP] |= 0x800;
		else
			m_csr[CSR::MIP] &= ~0x800;

		// Handle interrupts.
		uint32_t mstatus = readCSR(CSR::MSTATUS);
		const bool ie = (bool)((mstatus & (1 << 3)) != 0);
		if (ie)
		{
			uint32_t mip = (m_csr[CSR::MIP] & 0x888);
			if (mip != 0)
			{
				writeCSR(CSR::MEPC, m_pc);
			
				if ((mip & 0x80) != 0)
				{
					writeCSR(CSR::MCAUSE, 0x80000000 | (1 << 7));	// Timer
					mip &= ~0x80;
				}
				else if ((mip & 0x800) != 0)
				{
					writeCSR(CSR::MCAUSE, 0x80000000 | (1 << 11));	// External
					mip &= ~0x800;
				}
				else if ((mip & 0x8) != 0)
				{
					writeCSR(CSR::MCAUSE, 0x00000000 | (1 << 11));	// Software
					mip &= ~0x8;
				}

				// Push MIE and then disable interrupts.
				mstatus &= ~(1 << 3);
				mstatus |= 1 << 4;
				writeCSR(CSR::MSTATUS, mstatus);

				const uint32_t mtvec = readCSR(CSR::MTVEC);
				m_pc = mtvec;

				m_csr[CSR::MIP] = mip;

				m_waitForInterrupt = false;
			}
		}

		const uint32_t word = m_icache->readU32(m_pc);

		if (m_trace)
		{
			*m_trace << str(L"%08x", m_pc);
			for (int32_t i = 1; i < 32; ++i)
				*m_trace << L" " << str(L"%08x", m_registers[i]);
			*m_trace << Endl;
		}

		// if ((word & 0x3) == 0x3)
			m_next = m_pc + 4;
		// else
		// 	m_next = m_pc + 2;

		// zero register is hardcoded.
		R(0) = 0;

		if (!decode(word))
		{
			log::error << L"Decode (" << str(L"%08x", word) << L") failed at PC " << str(L"%08x", m_pc) << Endl;
			return false;
		}

		// zero register is hardcoded.
		R(0) = 0;

		m_retiredPC = m_pc;
		m_pc = m_next;

		if (!m_bus->tick(this))
			return false;

		m_cycles++;
	}
	
	return true;
}

uint32_t& CPU_hl::getInterruptPending()
{
	return m_pending;
}

void CPU_hl::flushCaches()
{
	m_dcache->flush();
	m_icache->flush();
	m_bus->reset();
}

void CPU_hl::setPC(uint32_t value)
{
	m_pc = value;
	m_waitForInterrupt = false;
	m_bus->reset();
}

uint32_t CPU_hl::getPC() const
{
	return m_retiredPC;
}

void CPU_hl::setRegister(uint32_t index, uint32_t value)
{
	m_registers[index] = value;
}

uint32_t CPU_hl::getRegister(uint32_t index) const
{
	return m_registers[index];
}

uint32_t CPU_hl::getCSR(uint16_t csr) const
{
	return readCSR(csr);
}

uint32_t CPU_hl::snoopReadU32(uint32_t address) const
{
	return m_busAccess->readU32(m_pc, address);
}

void CPU_hl::reset()
{
	m_pc = 0x000000000;

	for (uint32_t i = 0; i < sizeof_array(m_registers); ++i)
		m_registers[i] = i;
	m_registers[2] = 0x20110000;

	for (uint32_t i = 0; i < sizeof_array(m_csr); ++i)
		m_csr[i] = 0x00000000;

	writeCSR(CSR::MSTATUS, 0x8);
}

void CPU_hl::push(uint32_t value)
{
	const uint32_t sp = m_registers[2] - 4;
	MEM_WR(sp, value);
	m_registers[2] = sp;
}

bool CPU_hl::decode(uint32_t word)
{
	#include "Instructions.inl"
}

void CPU_hl::ecall()
{
}

uint32_t CPU_hl::readCSR(uint16_t csr) const
{
	if (csr == 0xc00)
		return (uint32_t)m_cycles;
	else if (csr == 0xc80)
		return (uint32_t)(m_cycles >> 32);
	else if (csr == MTIME || csr == MTIMEH)
	{
		const uint64_t time = (uint64_t)(m_timer.getElapsedTime() * 1000);
		if (csr == MTIME)
			return (uint32_t)time;
		else
			return (uint32_t)(time >> 32);
	}
	else
		return m_csr[csr];
}

void CPU_hl::writeCSR(uint16_t csr, uint32_t value)
{
	m_csr[csr] = value;
}

void CPU_hl::returnFromInterrupt()
{
	// Pop MIE.
	uint32_t mstatus = readCSR(CSR::MSTATUS);
	const bool mpie = (bool)((mstatus & (1 << 4)) != 0);
	mstatus &= ~(1 << 4);
	if (mpie)
		mstatus |= 1 << 3;
	else
		mstatus &= ~(1 << 3);
	writeCSR(CSR::MSTATUS, mstatus);

	// Return from interrupt.
	PC_NEXT = readCSR(CSR::MEPC);
}

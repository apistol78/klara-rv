/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "Emulator2/CPU/Bus.h"
#include "Emulator2/CPU/GL/CPU_gate.h"

#include "verilated.h"
#include "verilated_fst_c.h"

#include "Emulator2/CPU/GL/verilator/VCPU_top.h"
#include "Emulator2/CPU/GL/verilator/VCPU_top___024root.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"CPU_gate", CPU_gate, ICPU)

CPU_gate::CPU_gate(Bus* bus)
:   m_bus(bus)
{
	m_tb = new VCPU_top();
    m_tb->reset = 0;
	m_tb->clock = 0;
    m_tb->bus_ready = 0;
    m_tb->bus_rdata = 0;

    const char* trace = "CPU_gate.fst";
	if (trace)
	{
		Verilated::traceEverOn(true);
		m_tfp = new VerilatedFstC;
		m_tb->trace(m_tfp, 99);
		m_tfp->open(trace);
	}

	m_tb->eval();
}

CPU_gate::~CPU_gate()
{
    m_tb->final();

    if (m_tfp)
    {
		m_tfp->close();
		delete m_tfp;
    }

    delete m_tb;
}

void CPU_gate::jump(uint32_t address)
{
    m_tb->rootp->CPU_top__DOT__cpu__DOT__fetch__DOT__pc = address;
}

void CPU_gate::setSP(uint32_t sp)
{
    m_tb->rootp->CPU_top__DOT__cpu__DOT__registers__DOT__r[2] = sp;
}

bool CPU_gate::tick(uint32_t count)
{
    m_time++;

	m_tb->clock = 1;
	m_tb->eval();

    if (m_tfp)
        m_tfp->dump(m_time);

    m_tb->bus_ready = 0;
    if (m_tb->bus_request)
    {
        if (!m_lastBusRequest)
        {
            if (!m_tb->bus_rw)
            {
                const uint32_t data = m_bus->readU32(m_tb->bus_address);
                m_tb->bus_rdata = data;
            }
            else
            {
                m_bus->writeU32(m_tb->bus_address, m_tb->bus_wdata);
            }
        }

        m_tb->bus_ready = 1;
    }
    m_lastBusRequest = (bool)m_tb->bus_request;

    m_bus->tick(this);

    m_time++;

   	m_tb->clock = 0;
	m_tb->eval();

    if (m_tfp)
        m_tfp->dump(m_time);

    return true;
}

void CPU_gate::interrupt(uint32_t mask)
{
}

/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Object.h>
#include <Core/Ref.h>
#include <Core/Containers/StaticSet.h>
#include <Net/TcpSocket.h>

class Bus;
class ICPU;

class GDBServer : public traktor::Object
{
	T_RTTI_CLASS;

public:
	constexpr static int32_t ModeRun = 0;
	constexpr static int32_t ModeStep = 1;
	constexpr static int32_t ModeStopped = 2;
	constexpr static int32_t ModeKilled = 3;

	explicit GDBServer(ICPU* cpu, Bus* bus);

	virtual ~GDBServer();

	bool create();

	void process();

	void tick();

	void setMode(int32_t mode);

	int32_t getMode() const { return m_mode; }

private:
	traktor::Ref< ICPU > m_cpu;
	traktor::Ref< Bus > m_bus;
	traktor::Ref< traktor::net::TcpSocket > m_listenSocket;
	traktor::Ref< traktor::net::TcpSocket > m_clientSocket;
	traktor::StaticSet< uint32_t, 16 > m_breakpoints;
	int32_t m_mode = ModeStopped;
	uint32_t m_lastPC = ~0U;
};

/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "Emulator2/CPU/Bus.h"
#include "Emulator2/CPU/GDBServer.h"
#include "Emulator2/CPU/ICPU.h"

#include <Core/Io/StringReader.h>
#include <Core/Io/StringOutputStream.h>
#include <Core/Io/Utf8Encoding.h>
#include <Core/Log/Log.h>
#include <Core/Misc/Endian.h>
#include <Core/Misc/SafeDestroy.h>
#include <Core/Misc/String.h>
#include <Core/Misc/TString.h>
#include <Net/SocketAddressIPv4.h>
#include <Net/SocketSet.h>
#include <Net/SocketStream.h>

using namespace traktor;

#define T_GDB_LOG(x) log::info << x << Endl;
#define T_GDB_LOG_VERBOSE(x)

T_IMPLEMENT_RTTI_CLASS(L"GDBServer", GDBServer, Object)

namespace
{

	uint8_t readU8(Bus* bus, uint32_t address)
	{
		const uint32_t ra = address & ~3;
		const uint32_t rb = address & 3;
		const uint32_t r = bus->readU32(ra);
		switch(rb)
		{
		case 0:
			return r & 0xff;
		case 1:
			return (r >> 8) & 0xff;
		case 2:
			return (r >> 16) & 0xff;
		case 3:
			return (r >> 24) & 0xff;
		}
		return 0;
	}

	void writeU8(Bus* bus, uint32_t address, uint8_t value)
	{
		const uint32_t wa = address & ~3;
		const uint32_t wb = address & 3;
		uint32_t w = bus->readU32(wa);
		switch(wb)
		{
		case 0:
			w = (w & 0xffffff00) | value;
			break;
		case 1:
			w = (w & 0xffff00ff) | (value << 8);
			break;
		case 2:
			w = (w & 0xff00ffff) | (value << 16);
			break;
		case 3:
			w = (w & 0x00ffffff) | (value << 24);
			break;
		}
		bus->writeU32(wa, w, ~0U);	
	}

	void send(net::TcpSocket* socket, const std::string& msg)
	{
		const char hex[] = "0123456789ABCDEF";
		uint8_t cs = 0;

		T_GDB_LOG_VERBOSE(L"[GDB] sending \"" << mbstows(msg) << L"\"");

		socket->send('+');
		socket->send('$');
		for (const char ch : msg)
		{
			socket->send(ch);
			cs += (uint8_t)ch;
		}
		socket->send('#');
		socket->send(hex[cs >> 4]);
		socket->send(hex[cs & 15]);
	}

	std::string registerToHex(uint32_t r)
	{
		swap8in32(r);
		return wstombs(str(L"%08x", r));
	}

}

GDBServer::GDBServer(ICPU* cpu, Bus* bus)
:	m_cpu(cpu)
,	m_bus(bus)
{
}

GDBServer::~GDBServer()
{
	safeClose(m_clientSocket);
	safeClose(m_listenSocket);
}

bool GDBServer::create()
{
	m_listenSocket = new net::TcpSocket();
	if (!m_listenSocket->bind(net::SocketAddressIPv4(12345), true))
		return false;
	if (!m_listenSocket->listen())
		return false;

	return true;
}

void GDBServer::process()
{
	if (m_clientSocket)
	{
		AlignedVector< char > buf;
		int32_t timeout = 0;

		buf.reserve(256);

		// Receive commands from GDB.
		while (m_clientSocket != nullptr && m_clientSocket->select(true, false, false, timeout) > 0)
		{
			timeout = 100;

			char ch;
			if (m_clientSocket->recv(&ch, 1) <= 0)
			{
				T_GDB_LOG(L"[GDB] client disconnected.");
				safeClose(m_clientSocket);
				setMode(ModeRun);
				continue;
			}

			if (ch == '\x03')
			{
				// Async break.
				T_GDB_LOG(L"[GDB] async break.");
				setMode(ModeStopped);
			}

			else if (ch == '$')
			{
				// Receive message until end character.
				buf.resize(0);
				for (;;)
				{
					m_clientSocket->recv(&ch, 1);
					if (ch == '#')
						break;
					buf.push_back(ch);
				}
				const std::string msg(buf.begin(), buf.end());

				// Read checksum.
				uint8_t cs[2];
				m_clientSocket->recv(cs, 2);

				T_GDB_LOG_VERBOSE(L"[GDB] got message \"" << mbstows(msg) << L"\"");

				// Process message.
				if (msg[0] == '?')
				{
					if (m_mode == ModeStopped)
						send(m_clientSocket, "S05");	// sigtrap
					else
						send(m_clientSocket, "");
				}
				else if (msg[0] == 'g')
				{
					// Return all registers.
					std::string data = msg.substr(1);
					for (uint32_t i = 0; i < 32; ++i)
						data += registerToHex(m_cpu->getRegister(i));
					data += registerToHex(m_cpu->getPC());
					send(m_clientSocket, data);
				}
				else if (msg[0] == 'G')
				{
					// Set all registers.
					m_cpu->flushCaches();
					
					std::string data = msg.substr(1);

					for (uint32_t i = 0; i < 32; ++i)
					{
						uint32_t r = parseString< uint32_t >(std::string("0x") + data.substr(i * 8, 8));
						swap8in32(r);
						m_cpu->setRegister(i, r);
					}

					uint32_t r = parseString< uint32_t >(std::string("0x") + data.substr(32 * 8, 8));
					swap8in32(r);
					m_cpu->setPC(r);

					send(m_clientSocket, "OK");
				}
				else if (msg[0] == 'm')
				{
					// Read memory.
					m_cpu->flushCaches();

					uint32_t addr, len;
					sscanf(msg.c_str() + 1, "%x,%x", &addr, &len);
					T_GDB_LOG_VERBOSE(L"[GDB] read " << len << L" bytes from " << str(L"%08x", addr));
					
					StringOutputStream ss;
					for (uint32_t i = 0; i < len; ++i)
					{
						const uint8_t b = readU8(m_bus, addr + i);
						ss << str(L"%02x", b);
					}

					send(m_clientSocket, wstombs(ss.str()));
				}
				else if (msg[0] == 'M')
				{
					// Write memory.
					m_cpu->flushCaches();

					uint32_t addr, len;
					sscanf(msg.c_str() + 1, "%x,%x", &addr, &len);
					T_GDB_LOG_VERBOSE(L"[GDB] write " << len << L" bytes to " << str(L"%08x", addr));

					std::string hexdata = msg.substr(msg.find(':')+1);
					for (uint32_t i = 0; i < len; i++)
					{
						const uint8_t b = parseString< uint8_t >(std::string("0x") + hexdata.substr(i * 2, 2));
						writeU8(m_bus, addr + i, b);
					}

					send(m_clientSocket, "OK");
				}
				else if (msg[0] == 'c')
				{
					send(m_clientSocket, "OK");
					setMode(ModeRun);
				}
				else if (msg[0] == 's')
				{
					send(m_clientSocket, "S05");
					setMode(ModeStep);
				}
				else if (msg[0] == 'k')
				{
					safeClose(m_clientSocket);
					setMode(ModeKilled);
				}
				else if (startsWith(msg, "Z0"))
				{
					uint32_t addr, len;
					sscanf(msg.c_str() + 3, "%x,%x", &addr, &len);
					m_breakpoints.insert(addr);
					send(m_clientSocket, "OK");
				}
				else if (startsWith(msg, "z0"))
				{
					uint32_t addr, len;
					sscanf(msg.c_str() + 3, "%x,%x", &addr, &len);
					m_breakpoints.erase(addr);
					send(m_clientSocket, "OK");
				}
				else if (startsWith(msg, "qSupported"))
					send(m_clientSocket, "");
				else if (startsWith(msg, "vCont?"))
					send(m_clientSocket, "");
				else if (startsWith(msg, "vMustReplyEmpty"))
					send(m_clientSocket, "");
				else
					send(m_clientSocket, "");
			}
		}
	}
	else
	{
		net::SocketSet ss;
		ss.add(m_listenSocket);

		net::SocketSet result;
		if (ss.select(true, false, false, 0, result) <= 0)
			return;

		m_clientSocket = m_listenSocket->accept();
		if (m_clientSocket != nullptr)
		{
			m_clientSocket->setNoDelay(true);
			m_clientSocket->setQuickAck(true);
			T_GDB_LOG(L"[GDB] client connected.");
		}
	}
}

void GDBServer::tick()
{
	if (m_mode != ModeRun && m_mode != ModeStep)
		return;

	for (uint32_t bp : m_breakpoints)
	{
		if (bp == m_cpu->getPC())
		{
			T_GDB_LOG(L"[GDB] breakpoint hit.");
			setMode(ModeStopped);
		}
	}
}

void GDBServer::setMode(int32_t mode)
{
	const wchar_t* modeNames[] =
	{
		L"Run",
		L"Step",
		L"Stopped",
		L"Killed"
	};

	if (mode != m_mode)
		T_GDB_LOG(L"[GDB] mode changed to " << modeNames[mode] << L" (from " << modeNames[m_mode] << L")");

	if (mode == ModeStopped)
		send(m_clientSocket, "S02");	// sigint

	m_mode = mode;
}

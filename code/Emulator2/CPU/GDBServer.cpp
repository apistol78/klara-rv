/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "Emulator2/CPU/GDBServer.h"

#include <Core/Io/StringReader.h>
#include <Core/Io/Utf8Encoding.h>
#include <Core/Log/Log.h>
#include <Core/Misc/String.h>
#include <Core/Misc/TString.h>
#include <Net/SocketAddressIPv4.h>
#include <Net/SocketSet.h>
#include <Net/SocketStream.h>

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"GDBServer", GDBServer, Object)

namespace
{

	void send(net::TcpSocket* socket, const std::string& msg)
	{
		const char hex[] = "0123456789ABCDEF";
		uint8_t cs = 0;

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

}

bool GDBServer::create()
{
	m_listenSocket = new net::TcpSocket();
	if (!m_listenSocket->bind(net::SocketAddressIPv4(12345)))
		return false;
	if (!m_listenSocket->listen())
		return false;

	return true;
}

void GDBServer::process()
{
	if (m_clientSocket)
	{
		// Receive commands from GDB.
		if (m_clientSocket->select(true, false, false, 0) > 0)
		{
			char ch;
			m_clientSocket->recv(&ch, 1);

			if (ch == '$')
			{
				// Receive message until end character.
				std::string msg;
				for (;;)
				{
					m_clientSocket->recv(&ch, 1);
					if (ch == '#')
						break;

					msg += ch;
				}

				// Read checksum.
				m_clientSocket->recv(&ch, 1);
				m_clientSocket->recv(&ch, 1);

				log::info << L"GDB, got message \"" << mbstows(msg) << L"\"" << Endl;

				// Process message.
				if (msg == "?")
					send(m_clientSocket, "S05");
				else if (msg == "c")
					send(m_clientSocket, "S05");
				else if (startsWith(msg, "qSupported"))
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
		if (ss.select(true, false, false, 100, result) <= 0)
			return;

		m_clientSocket = m_listenSocket->accept();
		log::info << L"GDB client connected." << Endl;
	}
}
/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "Emulator2/CPU/GDBServer.h"

#include <Core/Log/Log.h>
#include <Net/SocketAddressIPv4.h>
#include <Net/SocketSet.h>
#include <Net/SocketStream.h>

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"GDBServer", GDBServer, Object)

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

		net::SocketStream clientStream(m_clientSocket, true, true, 100);

		
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
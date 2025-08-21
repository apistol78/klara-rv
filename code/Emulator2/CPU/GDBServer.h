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
#include <Net/TcpSocket.h>

class GDBServer : public traktor::Object
{
	T_RTTI_CLASS;

public:
	bool create();

	void process();

private:
	traktor::Ref< traktor::net::TcpSocket > m_listenSocket;
	traktor::Ref< traktor::net::TcpSocket > m_clientSocket;
};

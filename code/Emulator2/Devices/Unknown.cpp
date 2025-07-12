/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "Emulator2/Devices/Unknown.h"

T_IMPLEMENT_RTTI_CLASS(L"Unknown", Unknown, IDevice)

bool Unknown::writeU32(uint32_t address, uint32_t value)
{
	return true;
}

uint32_t Unknown::readU32(uint32_t address) const
{
	return 0;
}

bool Unknown::tick(ICPU* cpu)
{
	return true;
}

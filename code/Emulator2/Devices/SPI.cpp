/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "Emulator2/Devices/SPI.h"

T_IMPLEMENT_RTTI_CLASS(L"SPI", SPI, IDevice)

bool SPI::writeU32(uint32_t address, uint32_t value, uint32_t mask)
{
	return true;
}

uint32_t SPI::readU32(uint32_t address) const
{
    if (address == 4)
        return 0xffffffff;
    else
	    return 0;
}

bool SPI::tick(ICPU* cpu, Bus* bus)
{
	return true;
}

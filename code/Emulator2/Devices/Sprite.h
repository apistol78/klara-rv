/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include "Emulator2/CPU/IDevice.h"

class Sprite : public IDevice
{
	T_RTTI_CLASS;

public:
	virtual bool writeU32(uint32_t address, uint32_t value, uint32_t mask) override final;

	virtual uint32_t readU32(uint32_t address) const override final;

	virtual bool tick(ICPU* cpu, Bus* bus) override final;

    bool getOverlay(uint32_t x, uint32_t y, uint8_t& outOverlay) const;

private:
    struct Data
    {
        int32_t x = 0;
        int32_t y = 0;
        uint8_t bits[64 * 64];
        bool visible = false;
    };

    Data m_data[4];
};
/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Ref.h>
#include "Emulator2/CPU/HL/ICache.h"

class Bus;

class ICache2W : public ICache
{
	T_RTTI_CLASS;

public:
	explicit ICache2W(Bus* bus);

    virtual ~ICache2W();

	virtual uint32_t readU32(uint32_t address) override final;

    virtual void flush() override final;

private:
    /*
    13 => 8192
    */

    struct Line
    {
        uint32_t tag[2];
        uint32_t word[2];
        bool valid[2];
        uint8_t last;
    };

	traktor::Ref< Bus > m_bus;
    Line m_data[8192];
    uint32_t m_hits;
    uint32_t m_misses;
};

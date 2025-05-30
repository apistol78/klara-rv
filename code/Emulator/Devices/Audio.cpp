/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <Core/Io/FileSystem.h>
#include "Emulator/Devices/Audio.h"

using namespace traktor;

T_IMPLEMENT_RTTI_CLASS(L"Audio", Audio, IDevice)

Audio::Audio()
{
    m_stream = FileSystem::getInstance().open(L"Rv32_audio.s16", File::FmWrite);
}

bool Audio::writeU32(uint32_t address, uint32_t value)
{
    if (m_channel == 0) // left
    {
        const int16_t sv = *(int16_t*)&value;
        if (m_written > 0 || abs(sv) > 256)
        {
            m_stream->write(&sv, sizeof(sv));
            m_stream->flush();
            m_written++;
        }
    }

    m_queued++;
    m_channel = (m_channel + 1) & 1;
	return true;
}

uint32_t Audio::readU32(uint32_t address) const
{
    return m_queued;
}

bool Audio::tick(CPU* cpu)
{
    if (++m_counter >= 9072)
    {
        if (m_queued > 0)
            m_queued--;

        m_counter = 0;
    }
	return true;
}

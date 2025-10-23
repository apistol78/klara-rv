/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include <cstring>

#include <Core/Io/FileSystem.h>
#include <Core/Log/Log.h>
#include <Core/Memory/Alloc.h>
#include <Core/Misc/String.h>
#include <Core/Thread/ThreadManager.h>
#include <Sound/AudioChannel.h>
#include <Sound/AudioSystem.h>
#include <Sound/IAudioBuffer.h>
#include <Sound/Pulse/AudioDriverPulse.h>

#include "Emulator2/Devices/Audio.h"

using namespace traktor;

class WrappedAudioBufferCursor : public RefCountImpl< sound::IAudioBufferCursor >
{
public:
	virtual void setParameter(sound::handle_t id, float parameter) {}

	virtual void disableRepeat() {}

	virtual void reset() {}
};

class WrappedAudioBuffer : public sound::IAudioBuffer
{
public:
	WrappedAudioBuffer()
	{
		m_buffer[0] = (float*)Alloc::acquireAlign(1024 * sizeof(float), 16, "");
		m_buffer[1] = (float*)Alloc::acquireAlign(1024 * sizeof(float), 16, "");
	}

	virtual Ref< sound::IAudioBufferCursor > createCursor() const
	{
		return new WrappedAudioBufferCursor();
	}

	virtual bool getBlock(sound::IAudioBufferCursor* cursor, const sound::IAudioMixer* mixer, sound::AudioBlock& outBlock) const
	{
		uint32_t samplesCount = std::min< uint32_t >(outBlock.samplesCount, queued());
		samplesCount = std::min< uint32_t >(samplesCount, 1024);

		if (samplesCount > 0)
		{
			for (int32_t i = 0; i < 2; ++i)
			{
				std::memcpy(m_buffer[i], m_queued[i].ptr(), samplesCount * sizeof(float));
				std::memcpy(m_queued[i].ptr(), m_queued[i].ptr() + samplesCount, (m_queued[i].size() - samplesCount) * sizeof(float));
				m_queued[i].resize(m_queued[i].size() - samplesCount);
				outBlock.samples[i] = m_buffer[i];
			}
			outBlock.maxChannel = 2;
		}

		outBlock.sampleRate = m_rate;
		outBlock.samplesCount = samplesCount;

		return true;
	}

	bool ready() const
	{
		return queued() < 4096;
	}

	void write(uint32_t value)
	{
		const uint16_t lh = (value >> 16);
		const uint16_t rh = (value & 0xffff);
		const float flh = (*(int16_t*)&lh) / 32767.0f;
		const float frh = (*(int16_t*)&rh) / 32767.0f;

		m_queued[0].push_back(flh);
		m_queued[1].push_back(frh);
	}

	uint32_t queued() const
	{
		return m_queued[0].size();
	}

	void setRate(uint32_t rate)
	{
		m_rate = rate;
	}

private:
	mutable AlignedVector< float > m_queued[2];
	float* m_buffer[2];
	uint32_t m_rate = 22050;
};


T_IMPLEMENT_RTTI_CLASS(L"Audio", Audio, IDevice)

Audio::Audio()
{
	Ref< sound::IAudioDriver > audioDriver = new sound::AudioDriverPulse();
	T_ASSERT(audioDriver);

	sound::AudioSystemCreateDesc desc;
	desc.channels = 1;
	desc.driverDesc.sampleRate = 22050;
	desc.driverDesc.bitsPerSample = 16;
	desc.driverDesc.hwChannels = 2;
	desc.driverDesc.frameSamples = 1024;

	m_audioSystem = new sound::AudioSystem(audioDriver);
	m_audioSystem->create(desc);

	m_audioBuffer = new WrappedAudioBuffer();

	sound::AudioChannel* channel = m_audioSystem->getChannel(0);
	channel->play(m_audioBuffer.ptr(), 0, 0.0f, false, 0);
}

bool Audio::ready(uint32_t address) const
{
	WrappedAudioBuffer* wab = (WrappedAudioBuffer*)m_audioBuffer.ptr();
	if (address == 0x0)
		return wab->ready();
	else
	 	return true;
}

bool Audio::writeU32(uint32_t address, uint32_t value)
{
	WrappedAudioBuffer* wab = (WrappedAudioBuffer*)m_audioBuffer.ptr();
	if (address == 0x0)
	{
		wab->write(value);
	}
	else if (address == 0x4)
	{
		// const uint32_t rate = 100000000 / (567ULL * (uint64_t)value);
		// log::info << L"[AUDIO] play back rate " << rate << L" (" << value << L")" << Endl;
		// wab->setRate(rate);
	}
	else
	{
		log::error << L"[AUDIO] attempt write to unknown address " << str(L"0x%08x", address) << L"." << Endl;
		return false;
	}

	return true;
}

uint32_t Audio::readU32(uint32_t address) const
{
	WrappedAudioBuffer* wab = (WrappedAudioBuffer*)m_audioBuffer.ptr();
	if (address == 0x0)
		return wab->queued();
	else
	{
		log::error << L"[AUDIO] attempt read from unknown address " << str(L"0x%08x", address) << L"." << Endl;
		return 0;
	}
}

bool Audio::tick(ICPU* cpu, Bus* bus)
{
	// WrappedAudioBuffer* wab = (WrappedAudioBuffer*)m_audioBuffer.ptr();
	// const uint32_t q = wab->queued();

	// if (m_callback && m_lastQ >= 2048 && q < 2048)
	// 	m_callback();

	// m_lastQ = q;
	return true;
}

void Audio::setCallback(const std::function< void() >& callback)
{
	m_callback = callback;
}

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
	virtual Ref< sound::IAudioBufferCursor > createCursor() const
	{
		return new WrappedAudioBufferCursor();
	}

	virtual bool getBlock(sound::IAudioBufferCursor* cursor, const sound::IAudioMixer* mixer, sound::AudioBlock& outBlock) const
	{
		const uint32_t samplesCount = std::min(outBlock.samplesCount, queued());

		for (int32_t i = 0; i < 2; ++i)
		{
			m_buffer[i].resize(samplesCount, 0.0f);
			std::memcpy(m_buffer[i].ptr(), m_queued[i].ptr(), samplesCount * sizeof(float));

			if (samplesCount < m_queued[i].size())
				m_queued[i].erase(m_queued[i].begin(), m_queued[i].begin() + samplesCount);
			else
				m_queued[i].resize(0);

			outBlock.samples[i] = m_buffer[i].ptr();
		}

		outBlock.sampleRate = m_rate;
		outBlock.samplesCount = samplesCount;
		outBlock.maxChannel = 2;

		return true;
	}

	void write(int32_t channel, float sample)
	{
		m_queued[channel].push_back(sample);
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
	mutable AlignedVector< float > m_buffer[2];
	uint32_t m_rate = 44100;
};


T_IMPLEMENT_RTTI_CLASS(L"Audio", Audio, IDevice)

Audio::Audio()
{
	Ref< sound::IAudioDriver > audioDriver = new sound::AudioDriverPulse();
	T_ASSERT(audioDriver);

	sound::AudioSystemCreateDesc desc;
	desc.channels = 1;
	desc.driverDesc.sampleRate = 44100;
	desc.driverDesc.bitsPerSample = 16;
	desc.driverDesc.hwChannels = 2;
	desc.driverDesc.frameSamples = 1024;

	m_audioSystem = new sound::AudioSystem(audioDriver);
	m_audioSystem->create(desc);

	m_audioBuffer = new WrappedAudioBuffer();

	sound::AudioChannel* channel = m_audioSystem->getChannel(0);
	channel->play(m_audioBuffer.ptr(), 0, 0.0f, false, 0);
}

bool Audio::writeU32(uint32_t address, uint32_t value)
{
	WrappedAudioBuffer* wab = (WrappedAudioBuffer*)m_audioBuffer.ptr();

	if (address == 0x0)
	{
		while (wab->queued() > 4096)
			ThreadManager::getInstance().getCurrentThread()->sleep(1);

		const int16_t sv = *(int16_t*)&value;
		wab->write(m_channel, sv / 32767.0f);
		m_channel = (m_channel + 1) & 1;
	}
	else if (address == 0x4)
	{
		const uint32_t rate = 100000000 / value;
		log::info << L"[AUDIO] play back rate " << rate << Endl;
		wab->setRate(rate);
	}

	return true;
}

uint32_t Audio::readU32(uint32_t address) const
{
	WrappedAudioBuffer* wab = (WrappedAudioBuffer*)m_audioBuffer.ptr();
	return wab->queued();
}

bool Audio::tick(ICPU* cpu)
{
	WrappedAudioBuffer* wab = (WrappedAudioBuffer*)m_audioBuffer.ptr();
	const uint32_t q = wab->queued();

	if (m_lastQ >= 2048 && q < 2048)
		m_callback();

	m_lastQ = q;
	return true;
}

void Audio::setCallback(const std::function< void() >& callback)
{
	m_callback = callback;
}

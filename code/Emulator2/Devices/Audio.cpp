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
#include <Core/Misc/Align.h>
#include <Core/Misc/String.h>
#include <Core/Thread/Acquire.h>
#include <Core/Thread/Semaphore.h>
#include <Core/Thread/ThreadManager.h>
#include <Sound/AudioChannel.h>
#include <Sound/AudioSystem.h>
#include <Sound/IAudioBuffer.h>
#include <Sound/Pulse/AudioDriverPulse.h>

#include "Emulator2/CPU/Bus.h"
#include "Emulator2/Devices/Audio.h"

using namespace traktor;

//==========================

class AudioChannel
{
public:
	void tick(Bus* bus);

	uint32_t read();

	void append(uint32_t address, uint32_t count, uint8_t mode);

	void replace(uint32_t address, uint32_t count, uint8_t mode);

	bool busy() const;

private:
	uint32_t m_dmaAddress = 0;
	uint32_t m_dmaCount = 0;
	uint8_t m_dmaMode = 0;
	uint32_t m_dmaNextAddress = 0;
	uint32_t m_dmaNextCount = 0;
	uint8_t m_dmaNextMode = 0;
	CircularVector< uint32_t, 4096 > m_queue;
};

void AudioChannel::tick(Bus* bus)
{
	if (m_dmaCount > 0)
	{
		if (!m_queue.full())
		{
			const uint32_t data = bus->readU32(m_dmaAddress);
			if (m_dmaMode == 0)	// mono
			{
				const uint16_t* p = (const uint16_t*)&data;
				m_queue.push_back(p[0] | ((uint32_t)p[0] << 16));
				m_queue.push_back(p[1] | ((uint32_t)p[1] << 16));
			}
			else	// stereo
			{
				m_queue.push_back(data);
			}
			m_dmaAddress += 4;
			m_dmaCount--;
		}
	}
	else
	{
		m_dmaAddress = m_dmaNextAddress;
		m_dmaCount = m_dmaNextCount;
		m_dmaMode = m_dmaNextMode;
		m_dmaNextAddress = 0;
		m_dmaNextCount = 0;
		m_dmaNextMode = 0;
	}
}

uint32_t AudioChannel::read()
{
	uint32_t value = 0;
	if (!m_queue.empty())
	{
		value = m_queue.front();
		m_queue.pop_front();
	}
	return value;
}

void AudioChannel::append(uint32_t address, uint32_t count, uint8_t mode)
{
	m_dmaNextAddress = address;
	m_dmaNextCount = mode ? count : (count >> 1);
	m_dmaNextMode = mode;
}

void AudioChannel::replace(uint32_t address, uint32_t count, uint8_t mode)
{
	m_dmaAddress = address;
	m_dmaCount = mode ? count : (count >> 1);
	m_dmaMode = mode;
	m_dmaNextAddress = 0;
	m_dmaNextCount = 0;
	m_dmaNextMode = 0;
}

bool AudioChannel::busy() const
{
	return m_dmaNextCount != 0;
}

//==========================

class AudioBufferCursor : public RefCountImpl< sound::IAudioBufferCursor >
{
public:
	virtual void setParameter(sound::handle_t id, float parameter) {}

	virtual void disableRepeat() {}

	virtual void reset() {}
};

//==========================

class AudioBuffer : public sound::IAudioBuffer
{
public:
	AudioBuffer()
	{
		m_buffer[0] = (float*)Alloc::acquireAlign(1024 * sizeof(float), 16, "");
		m_buffer[1] = (float*)Alloc::acquireAlign(1024 * sizeof(float), 16, "");
	}

	virtual Ref< sound::IAudioBufferCursor > createCursor() const
	{
		return new AudioBufferCursor();
	}

	virtual bool getBlock(sound::IAudioBufferCursor* cursor, const sound::IAudioMixer* mixer, sound::AudioBlock& outBlock) const
	{
		T_ANONYMOUS_VAR(Acquire< Semaphore >)(m_lock);

		const uint32_t samplesCount = std::min< uint32_t >(outBlock.samplesCount, 128);

		float* pl = m_buffer[0];
		float* pr = m_buffer[1];

		for (int32_t s = 0; s < samplesCount; ++s)
		{
			*pl = 0.0f;
			*pr = 0.0f;

			for (int32_t i = 0; i < sizeof_array(m_channels); ++i)
			{
				const uint32_t data = m_channels[i].read();
				const int16_t* dp = (const int16_t*)&data;
				*pl += (float)dp[0] / 32767.0f;
				*pr += (float)dp[1] / 32767.0f;
			}

			pl++;
			pr++;
		}

		outBlock.sampleRate = m_rate;
		outBlock.samplesCount = samplesCount;
		outBlock.samples[0] = m_buffer[0];
		outBlock.samples[1] = m_buffer[1];
		outBlock.maxChannel = 2;

		return true;
	}

private:
	friend class Audio;

	mutable Semaphore m_lock;
	mutable AudioChannel m_channels[16];
	float* m_buffer[2];
	uint32_t m_rate = 22050;
};

//==========================

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
	desc.driverDesc.frameSamples = 256;

	m_audioSystem = new sound::AudioSystem(audioDriver);
	m_audioSystem->create(desc);

	m_audioBuffer = new AudioBuffer();

	sound::AudioChannel* channel = m_audioSystem->getChannel(0);
	channel->play(m_audioBuffer.ptr(), 0, 0.0f, false, 0);
}

bool Audio::ready(uint32_t address) const
{
 	return true;
}

bool Audio::writeU32(uint32_t address, uint32_t value, uint32_t mask)
{
	AudioBuffer* audioBuffer = (AudioBuffer*)m_audioBuffer.ptr();
	T_ANONYMOUS_VAR(Acquire< Semaphore >)(audioBuffer->m_lock);

	if (address == (0xf0 << 2))
	{
		const uint32_t rate = 100000000 / (567ULL * (uint64_t)value);
		log::info << L"[AUDIO] play back rate " << rate << L" (" << value << L")" << Endl;
		// wab->setRate(rate);
	}
	else
	{
		const int32_t na = address >> 2;
		const int32_t ch = na / 4;
		const int32_t ca = na % 4;
		if (ch < 16)
		{
			if (ca == 0)
			{
				m_latchAddress[ch] = value;
			}
			else if (ca == 1)
			{
				const uint32_t mode = value & 0xff000000;
				const uint32_t count = value & 0x00ffffff;

				if ((mode & 0x10000000) == 0x10000000)
				{
					audioBuffer->m_channels[ch].replace(
						m_latchAddress[ch],
						count,
						(mode & 0x20000000) ? 1 : 0
					);
				}
				else
				{
					audioBuffer->m_channels[ch].append(
						m_latchAddress[ch],
						count,
						(mode & 0x20000000) ? 1 : 0
					);
				}
			}
			else if (ca == 2)
			{
				// Channel volume
			}
		}
		else
		{
			log::error << L"[AUDIO] attempt write to unknown address " << str(L"0x%08x", address) << L"." << Endl;
			return false;
		}
	}

	return true;
}

uint32_t Audio::readU32(uint32_t address) const
{
	AudioBuffer* audioBuffer = (AudioBuffer*)m_audioBuffer.ptr();
	T_ANONYMOUS_VAR(Acquire< Semaphore >)(audioBuffer->m_lock);

	if (address == (0xf0 << 2))
	{
		uint32_t busy = 0;
		for (int32_t i = 0; i < 16; ++i)
		{
			if (audioBuffer->m_channels[i].busy())
				busy |= 1 << i;
		}
		return busy;
	}
	else
	{
		log::error << L"[AUDIO] attempt read from unknown address " << str(L"0x%08x", address) << L"." << Endl;
		return 0;
	}
}

bool Audio::tick(ICPU* cpu, Bus* bus)
{
	AudioBuffer* audioBuffer = (AudioBuffer*)m_audioBuffer.ptr();
	T_ANONYMOUS_VAR(Acquire< Semaphore >)(audioBuffer->m_lock);

	for (int32_t i = 0; i < 16; ++i)
		audioBuffer->m_channels[i].tick(bus);

	return true;
}

void Audio::setCallback(const std::function< void() >& callback)
{
	m_callback = callback;
}

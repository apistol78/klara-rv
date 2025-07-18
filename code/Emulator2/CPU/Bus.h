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
#include <Core/Containers/StaticVector.h>

class ICPU;
class IDevice;

class Bus : public traktor::Object
{
	T_RTTI_CLASS;

public:
	void map(uint32_t start, uint32_t end, bool cacheable, bool tick, IDevice* device);

	IDevice* device(uint32_t address) const;

	bool cacheable(uint32_t address) const;

	bool writeU32(uint32_t address, uint32_t value);

	uint32_t readU32(uint32_t address) const;

	bool tick(ICPU* cpu) const;

	bool error() const { return m_error; }

private:
	struct MappedDevice
	{
		uint32_t start;
		uint32_t end;
		bool cacheable;
		traktor::Ref< IDevice > device;
	};

	traktor::StaticVector< MappedDevice, 32 > m_mappedDevices;
	traktor::StaticVector< IDevice*, 32 > m_tickDevices;
	mutable const MappedDevice* m_last = nullptr;
	mutable bool m_error = false;

	const MappedDevice* findMappedDevice(uint32_t address) const;
};

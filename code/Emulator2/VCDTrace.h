/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include <Core/Object.h>
#include <Core/Containers/AlignedVector.h>
#include <Core/Io/OutputStream.h>

class VCDTrace : public traktor::Object
{
	T_RTTI_CLASS;

public:
	int32_t declare(const std::wstring& name);

	void tick();

	void set(int32_t signal, bool value);

	void dump(traktor::OutputStream& os) const;

private:
	struct Trace
	{
		int32_t signal;
		int64_t time;
		bool value;
	};
	
	traktor::AlignedVector< std::wstring > m_names;
	traktor::AlignedVector< bool > m_values;
	traktor::AlignedVector< Trace > m_traces;
	int64_t m_time = 0;
};

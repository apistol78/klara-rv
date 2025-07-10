/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/Timer.h"

uint32_t hal_timer_get_ms()
{
 	uint32_t ms;
	__asm__ volatile (
		"rdtime %0"
		: "=r" (ms)
	);
	return ms;   
}

uint64_t hal_timer_get_cycles()
{
	volatile uint32_t mtimeh;
	volatile uint32_t mtimel;
	volatile uint32_t tmp;

	for (;;)
	{
		__asm__ volatile ( "rdcycleh %0" : "=r" (tmp) );
		__asm__ volatile ( "rdcycle  %0" : "=r" (mtimel) );
		__asm__ volatile ( "rdcycleh %0" : "=r" (mtimeh) );
		if (mtimeh == tmp)
			break;
	}

	return (uint64_t)(
		(((uint64_t)mtimeh) << 32) | mtimel
	);
}

void hal_timer_wait_ms(uint32_t ms)
{
	const uint32_t until = hal_timer_get_ms() + ms;
	while (hal_timer_get_ms() < until)
	{
		__asm__ volatile (
			"nop	\n"
			"nop	\n"
			"nop	\n"
			"nop	\n"
			"nop	\n"
		);
	}
}

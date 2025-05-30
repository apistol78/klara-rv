/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#include "HAL/CSR.h"
#include "HAL/Interrupt.h"

enum
{
	RISCV_INT_POS_MSI = 3,
	RISCV_INT_POS_MTI = 7,
	RISCV_INT_POS_MEI = 11,
	RISCV_INT_POS_SSI = 1,
	RISCV_INT_POS_STI = 5,
	RISCV_INT_POS_SEI = 9,
	RISCV_INT_POS_USI = 0,
	RISCV_INT_POS_UTI = 4,
	RISCV_INT_POS_UEI = 8,
};

enum
{
	RISCV_INT_MASK_MSI = (1UL << RISCV_INT_POS_MSI),
	RISCV_INT_MASK_MTI = (1UL << RISCV_INT_POS_MTI),
	RISCV_INT_MASK_MEI = (1UL << RISCV_INT_POS_MEI),
	RISCV_INT_MASK_SSI = (1UL << RISCV_INT_POS_SSI),
	RISCV_INT_MASK_STI = (1UL << RISCV_INT_POS_STI),
	RISCV_INT_MASK_SEI = (1UL << RISCV_INT_POS_SEI),
	RISCV_INT_MASK_USI = (1UL << RISCV_INT_POS_USI),
	RISCV_INT_MASK_UTI = (1UL << RISCV_INT_POS_UTI),
	RISCV_INT_MASK_UEI = (1UL << RISCV_INT_POS_UEI),
};

enum
{
	RISCV_EXCP_INSTRUCTION_ADDRESS_MISALIGNED = 0,	/* Instruction address misaligned */
	RISCV_EXCP_INSTRUCTION_ACCESS_FAULT = 1,		/* Instruction access fault	*/
	RISCV_EXCP_ILLEGAL_INSTRUCTION = 2,				/* Illegal instruction */
	RISCV_EXCP_BREAKPOINT = 3,						/* Breakpoint */
	RISCV_EXCP_LOAD_ADDRESS_MISALIGNED = 4,			/* Load address misaligned */
	RISCV_EXCP_LOAD_ACCESS_FAULT = 5,				/* Load access fault */
	RISCV_EXCP_STORE_AMO_ADDRESS_MISALIGNED	= 6,	/* Store/AMO address misaligned	 */
	RISCV_EXCP_STORE_AMO_ACCESS_FAULT = 7,			/* Store/AMO access fault */
	RISCV_EXCP_ENVIRONMENT_CALL_FROM_U_MODE = 8,	/* Environment call from U-mode	*/
	RISCV_EXCP_ENVIRONMENT_CALL_FROM_S_MODE = 9,	/* Environment call from S-mode	*/
	RISCV_EXCP_RESERVED10 = 10,						/* Reserved	*/
	RISCV_EXCP_ENVIRONMENT_CALL_FROM_M_MODE = 11,	/* Environment call from M-mode	*/
	RISCV_EXCP_INSTRUCTION_PAGE_FAULT = 12,			/* Instruction page fault */
	RISCV_EXCP_LOAD_PAGE_FAULT = 13,				/* Load page fault */
	RISCV_EXCP_RESERVED14 = 14,						/* Reserved	*/
	RISCV_EXCP_STORE_AMO_PAGE_FAULT = 15,			/* Store/AMO page fault */
};

#define PLIC_ENABLE		(volatile uint32_t*)(PLIC_BASE + 0x00002000)
#define PLIC_CLAIM_0	(volatile uint32_t*)(PLIC_BASE + 0x00200004)
#define PLIC_COMPLETE_0	(volatile uint32_t*)(PLIC_BASE + 0x00200004)

static irq_handler_t g_handlers[] = { 0, 0, 0, 0, 0, 0 };
static uint32_t g_interrupt_enable = 0;

#pragma GCC push_options
#pragma GCC optimize ("align-functions=4")

static void irq_entry() __attribute__ ((interrupt ("machine")));

static void irq_entry()
{
	uint32_t cause = hal_csr_read_mcause();
	if (cause & MCAUSE_INTERRUPT_BIT_MASK)
	{
		cause &= 0xffff;
		if (cause == RISCV_INT_MASK_MTI)
		{
			// Timer interrupt.
			const irq_handler_t handler = g_handlers[IRQ_SOURCE_TIMER];
			if (handler)
				handler(IRQ_SOURCE_TIMER);
		}
		else if (cause == RISCV_INT_MASK_MEI)
		{
			// External interrupt, read PLIC to determine source.
			const uint32_t claimed = *PLIC_CLAIM_0;
			if (claimed)
			{
				// Call appropriate handler for source.
				const irq_handler_t handler = g_handlers[claimed];
				if (handler)
					handler(claimed);
			}
			*PLIC_COMPLETE_0 = claimed;
		}
	}
	else
	{
		// Software interrupt.
		const irq_handler_t handler = g_handlers[IRQ_SOURCE_ECALL];
		if (handler)
			handler(IRQ_SOURCE_ECALL);
	}
}

#pragma GCC pop_options

void hal_interrupt_init()
{
	// Global interrupt disable
	hal_csr_clr_bits_mstatus(MSTATUS_MIE_BIT_MASK);
	hal_csr_write_mie(0);

	// Setup the IRQ handler entry point
	hal_csr_write_mtvec((uint_xlen_t)irq_entry);

	// Global interrupt enable 
	hal_csr_set_bits_mie(MIE_MTI_BIT_MASK | MIE_MEI_BIT_MASK | MIE_MSI_BIT_MASK);
	hal_interrupt_enable();

	// Enable PLIC interrupts.
	*PLIC_ENABLE = 2 | 4 | 8 | 16;
}

void hal_interrupt_set_handler(uint32_t source, irq_handler_t handler)
{
	g_handlers[source] = handler;
}

irq_handler_t* hal_interrupt_get_handler(uint32_t source)
{
	return &g_handlers[source];
}

void hal_interrupt_enable()
{
	if (g_interrupt_enable++ == 0)
		hal_csr_set_bits_mstatus(MSTATUS_MIE_BIT_MASK);
}

void hal_interrupt_disable()
{
	if (--g_interrupt_enable == 0)
		hal_csr_clr_bits_mstatus(MSTATUS_MIE_BIT_MASK);
}

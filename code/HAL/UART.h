/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include "HAL/Common.h"

EXTERN_C void hal_uart_tx_u8(uint8_t data);

EXTERN_C void hal_uart_reset();

EXTERN_C uint32_t hal_uart_rx_full();

EXTERN_C uint32_t hal_uart_rx_empty();

EXTERN_C uint8_t hal_uart_rx_u8();

EXTERN_C uint16_t hal_uart_rx_u16();

EXTERN_C uint32_t hal_uart_rx_u32();
/*
 Klara-RTL
 Copyright (c) 2025 Anders Pistol.

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/
#pragma once

#include "HAL/Common.h"

EXTERN_C void hal_spi_begin(uint8_t rxEnable);

EXTERN_C void hal_spi_end();

EXTERN_C void hal_spi_write(uint8_t data);

EXTERN_C uint8_t hal_spi_read();

EXTERN_C void hal_spi_clear();

/*
 * Copyright (c) 2015 Wind River Systems, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file
 * @brief System/hardware module for the Quark D2000 BSP
 *
 * This module provides routines to initialize and support board-level
 * hardware for the Quark D2000 BSP.
 */

#include <nanokernel.h>
#include <arch/cpu.h>
#include <misc/printk.h>
#include <misc/__assert.h>
#include "soc.h"
#include <drivers/mvic.h>
#include <init.h>

/**
 *
 * _InitHardware - perform basic hardware initialization
 *
 * Initialize the Quark D2000 Interrupt Controller (MVIC) device driver and the
 * Intel 8250 UART device driver.
 * Also initialize the timer device driver, if required.
 *
 * RETURNS: N/A
 */
static int quark_d2000_init(struct device *arg)
{
	ARG_UNUSED(arg);

#ifdef CONFIG_UART_NS16550
	/* enable clock gating */
#ifdef CONFIG_UART_NS16550_PORT_0
	sys_set_bit(CLOCK_PERIPHERAL_BASE_ADDR, 17);
#endif
#ifdef CONFIG_UART_NS16550_PORT_1
	sys_set_bit(CLOCK_PERIPHERAL_BASE_ADDR, 18);
#endif
	sys_set_bit(CLOCK_PERIPHERAL_BASE_ADDR, 1);
#endif /* CONFIG_UART_NS16550 */

#ifdef CONFIG_I2C_DW_0
	/* Unmask interrupt */
	sys_clear_bit(I2C_MST_0_INT_MASK, 0);
#endif

	return 0;
}
SYS_INIT(quark_d2000_init, PRIMARY, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);

#ifdef CONFIG_MVIC
SYS_INIT(_mvic_init, PRIMARY, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
#endif /* CONFIG_IOAPIC */

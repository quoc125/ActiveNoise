/**
 * \file
 *
 * \brief Power Management Controller register vG related functionality.
 *
 * Copyright (C) 2017 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef _HPL_PMC_G_H_INCLUDED
#define _HPL_PMC_G_H_INCLUDED

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initializes cortex M4 core clock
 *
 */
void _pmc_init(void);

/**
 * \brief Enable the specified peripheral clock.
 *
 * \note The ID must not be shifted (i.e., 1 << ID_xxx).
 *
 * \param periph_id Peripheral ID
 *
 */
static inline void _pmc_enable_periph_clock(uint32_t periph_id)
{
	if (periph_id < 32) {
		if (!hri_pmc_get_PCSR0_reg(PMC, (1 << periph_id))) {
			hri_pmc_set_PCSR0_reg(PMC, (1 << periph_id));
		}
	} else {
		periph_id -= 32;
		if (!hri_pmc_get_PCSR1_reg(PMC, (1 << periph_id))) {
			hri_pmc_set_PCSR1_reg(PMC, (1 << periph_id));
		}
	}
}

/**
 * \brief Disable the specified peripheral clock.
 *
 * \note The ID must not be shifted (i.e., 1 << ID_xxx).
 *
 * \param periph_id Peripheral ID
 *
 */
static inline void _pmc_disable_periph_clock(uint32_t periph_id)
{
	if (periph_id < 32) {
		if (hri_pmc_get_PCSR0_reg(PMC, (1 << periph_id))) {
			hri_pmc_clear_PCSR0_reg(PMC, (1 << periph_id));
		}
	} else {
		periph_id -= 32;
		if (hri_pmc_get_PCSR1_reg(PMC, (1 << periph_id))) {
			hri_pmc_clear_PCSR1_reg(PMC, (1 << periph_id));
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif /* _HPL_PMC_G_H_INCLUDED */

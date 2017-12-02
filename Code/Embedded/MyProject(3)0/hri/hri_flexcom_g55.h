/**
 * \file
 *
 * \brief SAM FLEXCOM
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
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
 */

#ifdef _SAMG55_FLEXCOM_COMPONENT_
#ifndef _HRI_FLEXCOM_G55_H_INCLUDED_
#define _HRI_FLEXCOM_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_FLEXCOM_CRITICAL_SECTIONS)
#define FLEXCOM_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define FLEXCOM_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define FLEXCOM_CRITICAL_SECTION_ENTER()
#define FLEXCOM_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_flexcom_mr_reg_t;
typedef uint32_t hri_flexcom_rhr_reg_t;
typedef uint32_t hri_flexcom_thr_reg_t;

static inline void hri_flexcom_set_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR |= FLEXCOM_MR_OPMODE(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_get_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp = (tmp & FLEXCOM_MR_OPMODE(mask)) >> FLEXCOM_MR_OPMODE_Pos;
	return tmp;
}

static inline void hri_flexcom_write_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t data)
{
	uint32_t tmp;
	FLEXCOM_CRITICAL_SECTION_ENTER();
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp &= ~FLEXCOM_MR_OPMODE_Msk;
	tmp |= FLEXCOM_MR_OPMODE(data);
	((Flexcom *)hw)->FLEXCOM_MR = tmp;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR &= ~FLEXCOM_MR_OPMODE(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_MR_OPMODE_bf(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR ^= FLEXCOM_MR_OPMODE(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_read_MR_OPMODE_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp = (tmp & FLEXCOM_MR_OPMODE_Msk) >> FLEXCOM_MR_OPMODE_Pos;
	return tmp;
}

static inline void hri_flexcom_set_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR |= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_get_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_MR;
	tmp &= mask;
	return tmp;
}

static inline void hri_flexcom_write_MR_reg(const void *const hw, hri_flexcom_mr_reg_t data)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR = data;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR &= ~mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_MR_reg(const void *const hw, hri_flexcom_mr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_MR ^= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_mr_reg_t hri_flexcom_read_MR_reg(const void *const hw)
{
	return ((Flexcom *)hw)->FLEXCOM_MR;
}

static inline void hri_flexcom_set_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR |= FLEXCOM_THR_TXDATA(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_get_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp = (tmp & FLEXCOM_THR_TXDATA(mask)) >> FLEXCOM_THR_TXDATA_Pos;
	return tmp;
}

static inline void hri_flexcom_write_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t data)
{
	uint32_t tmp;
	FLEXCOM_CRITICAL_SECTION_ENTER();
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp &= ~FLEXCOM_THR_TXDATA_Msk;
	tmp |= FLEXCOM_THR_TXDATA(data);
	((Flexcom *)hw)->FLEXCOM_THR = tmp;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR &= ~FLEXCOM_THR_TXDATA(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_THR_TXDATA_bf(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR ^= FLEXCOM_THR_TXDATA(mask);
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_read_THR_TXDATA_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp = (tmp & FLEXCOM_THR_TXDATA_Msk) >> FLEXCOM_THR_TXDATA_Pos;
	return tmp;
}

static inline void hri_flexcom_set_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR |= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_get_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_THR;
	tmp &= mask;
	return tmp;
}

static inline void hri_flexcom_write_THR_reg(const void *const hw, hri_flexcom_thr_reg_t data)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR = data;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_clear_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR &= ~mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_flexcom_toggle_THR_reg(const void *const hw, hri_flexcom_thr_reg_t mask)
{
	FLEXCOM_CRITICAL_SECTION_ENTER();
	((Flexcom *)hw)->FLEXCOM_THR ^= mask;
	FLEXCOM_CRITICAL_SECTION_LEAVE();
}

static inline hri_flexcom_thr_reg_t hri_flexcom_read_THR_reg(const void *const hw)
{
	return ((Flexcom *)hw)->FLEXCOM_THR;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_get_RHR_RXDATA_bf(const void *const hw, hri_flexcom_rhr_reg_t mask)
{
	return (((Flexcom *)hw)->FLEXCOM_RHR & FLEXCOM_RHR_RXDATA(mask)) >> FLEXCOM_RHR_RXDATA_Pos;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_read_RHR_RXDATA_bf(const void *const hw)
{
	return (((Flexcom *)hw)->FLEXCOM_RHR & FLEXCOM_RHR_RXDATA_Msk) >> FLEXCOM_RHR_RXDATA_Pos;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_get_RHR_reg(const void *const hw, hri_flexcom_rhr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Flexcom *)hw)->FLEXCOM_RHR;
	tmp &= mask;
	return tmp;
}

static inline hri_flexcom_rhr_reg_t hri_flexcom_read_RHR_reg(const void *const hw)
{
	return ((Flexcom *)hw)->FLEXCOM_RHR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_FLEXCOM_G55_H_INCLUDED */
#endif /* _SAMG55_FLEXCOM_COMPONENT_ */

/**
 * \file
 *
 * \brief SAM PDC
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

#ifdef _SAMG55_PDC_COMPONENT_
#ifndef _HRI_PDC_G55_H_INCLUDED_
#define _HRI_PDC_G55_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_PDC_CRITICAL_SECTIONS)
#define PDC_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define PDC_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define PDC_CRITICAL_SECTION_ENTER()
#define PDC_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_pdc_periph_ptcr_reg_t;
typedef uint32_t hri_pdc_periph_ptsr_reg_t;
typedef uint32_t hri_pdc_periph_rcr_reg_t;
typedef uint32_t hri_pdc_periph_rncr_reg_t;
typedef uint32_t hri_pdc_periph_rnpr_reg_t;
typedef uint32_t hri_pdc_periph_rpr_reg_t;
typedef uint32_t hri_pdc_periph_tcr_reg_t;
typedef uint32_t hri_pdc_periph_tncr_reg_t;
typedef uint32_t hri_pdc_periph_tnpr_reg_t;
typedef uint32_t hri_pdc_periph_tpr_reg_t;

static inline void hri_pdc_write_PERIPH_PTCR_reg(const void *const hw, hri_pdc_periph_ptcr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_PTCR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_set_PERIPH_RPR_RXPTR_bf(const void *const hw, hri_pdc_periph_rpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RPR |= PDC_PERIPH_RPR_RXPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rpr_reg_t hri_pdc_get_PERIPH_RPR_RXPTR_bf(const void *const        hw,
                                                                       hri_pdc_periph_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RPR;
	tmp = (tmp & PDC_PERIPH_RPR_RXPTR(mask)) >> PDC_PERIPH_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RPR_RXPTR_bf(const void *const hw, hri_pdc_periph_rpr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_RPR;
	tmp &= ~PDC_PERIPH_RPR_RXPTR_Msk;
	tmp |= PDC_PERIPH_RPR_RXPTR(data);
	((Pdc *)hw)->PERIPH_RPR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RPR_RXPTR_bf(const void *const hw, hri_pdc_periph_rpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RPR &= ~PDC_PERIPH_RPR_RXPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RPR_RXPTR_bf(const void *const hw, hri_pdc_periph_rpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RPR ^= PDC_PERIPH_RPR_RXPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rpr_reg_t hri_pdc_read_PERIPH_RPR_RXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RPR;
	tmp = (tmp & PDC_PERIPH_RPR_RXPTR_Msk) >> PDC_PERIPH_RPR_RXPTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_RPR_reg(const void *const hw, hri_pdc_periph_rpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RPR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rpr_reg_t hri_pdc_get_PERIPH_RPR_reg(const void *const hw, hri_pdc_periph_rpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RPR_reg(const void *const hw, hri_pdc_periph_rpr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RPR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RPR_reg(const void *const hw, hri_pdc_periph_rpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RPR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RPR_reg(const void *const hw, hri_pdc_periph_rpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RPR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rpr_reg_t hri_pdc_read_PERIPH_RPR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_RPR;
}

static inline void hri_pdc_set_PERIPH_RCR_RXCTR_bf(const void *const hw, hri_pdc_periph_rcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RCR |= PDC_PERIPH_RCR_RXCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rcr_reg_t hri_pdc_get_PERIPH_RCR_RXCTR_bf(const void *const        hw,
                                                                       hri_pdc_periph_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RCR;
	tmp = (tmp & PDC_PERIPH_RCR_RXCTR(mask)) >> PDC_PERIPH_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RCR_RXCTR_bf(const void *const hw, hri_pdc_periph_rcr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_RCR;
	tmp &= ~PDC_PERIPH_RCR_RXCTR_Msk;
	tmp |= PDC_PERIPH_RCR_RXCTR(data);
	((Pdc *)hw)->PERIPH_RCR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RCR_RXCTR_bf(const void *const hw, hri_pdc_periph_rcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RCR &= ~PDC_PERIPH_RCR_RXCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RCR_RXCTR_bf(const void *const hw, hri_pdc_periph_rcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RCR ^= PDC_PERIPH_RCR_RXCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rcr_reg_t hri_pdc_read_PERIPH_RCR_RXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RCR;
	tmp = (tmp & PDC_PERIPH_RCR_RXCTR_Msk) >> PDC_PERIPH_RCR_RXCTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_RCR_reg(const void *const hw, hri_pdc_periph_rcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RCR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rcr_reg_t hri_pdc_get_PERIPH_RCR_reg(const void *const hw, hri_pdc_periph_rcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RCR_reg(const void *const hw, hri_pdc_periph_rcr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RCR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RCR_reg(const void *const hw, hri_pdc_periph_rcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RCR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RCR_reg(const void *const hw, hri_pdc_periph_rcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RCR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rcr_reg_t hri_pdc_read_PERIPH_RCR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_RCR;
}

static inline void hri_pdc_set_PERIPH_TPR_TXPTR_bf(const void *const hw, hri_pdc_periph_tpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TPR |= PDC_PERIPH_TPR_TXPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tpr_reg_t hri_pdc_get_PERIPH_TPR_TXPTR_bf(const void *const        hw,
                                                                       hri_pdc_periph_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TPR;
	tmp = (tmp & PDC_PERIPH_TPR_TXPTR(mask)) >> PDC_PERIPH_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TPR_TXPTR_bf(const void *const hw, hri_pdc_periph_tpr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_TPR;
	tmp &= ~PDC_PERIPH_TPR_TXPTR_Msk;
	tmp |= PDC_PERIPH_TPR_TXPTR(data);
	((Pdc *)hw)->PERIPH_TPR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TPR_TXPTR_bf(const void *const hw, hri_pdc_periph_tpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TPR &= ~PDC_PERIPH_TPR_TXPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TPR_TXPTR_bf(const void *const hw, hri_pdc_periph_tpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TPR ^= PDC_PERIPH_TPR_TXPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tpr_reg_t hri_pdc_read_PERIPH_TPR_TXPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TPR;
	tmp = (tmp & PDC_PERIPH_TPR_TXPTR_Msk) >> PDC_PERIPH_TPR_TXPTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_TPR_reg(const void *const hw, hri_pdc_periph_tpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TPR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tpr_reg_t hri_pdc_get_PERIPH_TPR_reg(const void *const hw, hri_pdc_periph_tpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TPR_reg(const void *const hw, hri_pdc_periph_tpr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TPR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TPR_reg(const void *const hw, hri_pdc_periph_tpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TPR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TPR_reg(const void *const hw, hri_pdc_periph_tpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TPR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tpr_reg_t hri_pdc_read_PERIPH_TPR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_TPR;
}

static inline void hri_pdc_set_PERIPH_TCR_TXCTR_bf(const void *const hw, hri_pdc_periph_tcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TCR |= PDC_PERIPH_TCR_TXCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tcr_reg_t hri_pdc_get_PERIPH_TCR_TXCTR_bf(const void *const        hw,
                                                                       hri_pdc_periph_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TCR;
	tmp = (tmp & PDC_PERIPH_TCR_TXCTR(mask)) >> PDC_PERIPH_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TCR_TXCTR_bf(const void *const hw, hri_pdc_periph_tcr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_TCR;
	tmp &= ~PDC_PERIPH_TCR_TXCTR_Msk;
	tmp |= PDC_PERIPH_TCR_TXCTR(data);
	((Pdc *)hw)->PERIPH_TCR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TCR_TXCTR_bf(const void *const hw, hri_pdc_periph_tcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TCR &= ~PDC_PERIPH_TCR_TXCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TCR_TXCTR_bf(const void *const hw, hri_pdc_periph_tcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TCR ^= PDC_PERIPH_TCR_TXCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tcr_reg_t hri_pdc_read_PERIPH_TCR_TXCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TCR;
	tmp = (tmp & PDC_PERIPH_TCR_TXCTR_Msk) >> PDC_PERIPH_TCR_TXCTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_TCR_reg(const void *const hw, hri_pdc_periph_tcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TCR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tcr_reg_t hri_pdc_get_PERIPH_TCR_reg(const void *const hw, hri_pdc_periph_tcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TCR_reg(const void *const hw, hri_pdc_periph_tcr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TCR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TCR_reg(const void *const hw, hri_pdc_periph_tcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TCR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TCR_reg(const void *const hw, hri_pdc_periph_tcr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TCR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tcr_reg_t hri_pdc_read_PERIPH_TCR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_TCR;
}

static inline void hri_pdc_set_PERIPH_RNPR_RXNPTR_bf(const void *const hw, hri_pdc_periph_rnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNPR |= PDC_PERIPH_RNPR_RXNPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rnpr_reg_t hri_pdc_get_PERIPH_RNPR_RXNPTR_bf(const void *const         hw,
                                                                          hri_pdc_periph_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RNPR;
	tmp = (tmp & PDC_PERIPH_RNPR_RXNPTR(mask)) >> PDC_PERIPH_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RNPR_RXNPTR_bf(const void *const hw, hri_pdc_periph_rnpr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_RNPR;
	tmp &= ~PDC_PERIPH_RNPR_RXNPTR_Msk;
	tmp |= PDC_PERIPH_RNPR_RXNPTR(data);
	((Pdc *)hw)->PERIPH_RNPR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RNPR_RXNPTR_bf(const void *const hw, hri_pdc_periph_rnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNPR &= ~PDC_PERIPH_RNPR_RXNPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RNPR_RXNPTR_bf(const void *const hw, hri_pdc_periph_rnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNPR ^= PDC_PERIPH_RNPR_RXNPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rnpr_reg_t hri_pdc_read_PERIPH_RNPR_RXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RNPR;
	tmp = (tmp & PDC_PERIPH_RNPR_RXNPTR_Msk) >> PDC_PERIPH_RNPR_RXNPTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_RNPR_reg(const void *const hw, hri_pdc_periph_rnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNPR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rnpr_reg_t hri_pdc_get_PERIPH_RNPR_reg(const void *const         hw,
                                                                    hri_pdc_periph_rnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RNPR_reg(const void *const hw, hri_pdc_periph_rnpr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNPR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RNPR_reg(const void *const hw, hri_pdc_periph_rnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNPR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RNPR_reg(const void *const hw, hri_pdc_periph_rnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNPR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rnpr_reg_t hri_pdc_read_PERIPH_RNPR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_RNPR;
}

static inline void hri_pdc_set_PERIPH_RNCR_RXNCTR_bf(const void *const hw, hri_pdc_periph_rncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNCR |= PDC_PERIPH_RNCR_RXNCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rncr_reg_t hri_pdc_get_PERIPH_RNCR_RXNCTR_bf(const void *const         hw,
                                                                          hri_pdc_periph_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RNCR;
	tmp = (tmp & PDC_PERIPH_RNCR_RXNCTR(mask)) >> PDC_PERIPH_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RNCR_RXNCTR_bf(const void *const hw, hri_pdc_periph_rncr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_RNCR;
	tmp &= ~PDC_PERIPH_RNCR_RXNCTR_Msk;
	tmp |= PDC_PERIPH_RNCR_RXNCTR(data);
	((Pdc *)hw)->PERIPH_RNCR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RNCR_RXNCTR_bf(const void *const hw, hri_pdc_periph_rncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNCR &= ~PDC_PERIPH_RNCR_RXNCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RNCR_RXNCTR_bf(const void *const hw, hri_pdc_periph_rncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNCR ^= PDC_PERIPH_RNCR_RXNCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rncr_reg_t hri_pdc_read_PERIPH_RNCR_RXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RNCR;
	tmp = (tmp & PDC_PERIPH_RNCR_RXNCTR_Msk) >> PDC_PERIPH_RNCR_RXNCTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_RNCR_reg(const void *const hw, hri_pdc_periph_rncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNCR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rncr_reg_t hri_pdc_get_PERIPH_RNCR_reg(const void *const         hw,
                                                                    hri_pdc_periph_rncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_RNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_RNCR_reg(const void *const hw, hri_pdc_periph_rncr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNCR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_RNCR_reg(const void *const hw, hri_pdc_periph_rncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNCR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_RNCR_reg(const void *const hw, hri_pdc_periph_rncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_RNCR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_rncr_reg_t hri_pdc_read_PERIPH_RNCR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_RNCR;
}

static inline void hri_pdc_set_PERIPH_TNPR_TXNPTR_bf(const void *const hw, hri_pdc_periph_tnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNPR |= PDC_PERIPH_TNPR_TXNPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tnpr_reg_t hri_pdc_get_PERIPH_TNPR_TXNPTR_bf(const void *const         hw,
                                                                          hri_pdc_periph_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TNPR;
	tmp = (tmp & PDC_PERIPH_TNPR_TXNPTR(mask)) >> PDC_PERIPH_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TNPR_TXNPTR_bf(const void *const hw, hri_pdc_periph_tnpr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_TNPR;
	tmp &= ~PDC_PERIPH_TNPR_TXNPTR_Msk;
	tmp |= PDC_PERIPH_TNPR_TXNPTR(data);
	((Pdc *)hw)->PERIPH_TNPR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TNPR_TXNPTR_bf(const void *const hw, hri_pdc_periph_tnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNPR &= ~PDC_PERIPH_TNPR_TXNPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TNPR_TXNPTR_bf(const void *const hw, hri_pdc_periph_tnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNPR ^= PDC_PERIPH_TNPR_TXNPTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tnpr_reg_t hri_pdc_read_PERIPH_TNPR_TXNPTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TNPR;
	tmp = (tmp & PDC_PERIPH_TNPR_TXNPTR_Msk) >> PDC_PERIPH_TNPR_TXNPTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_TNPR_reg(const void *const hw, hri_pdc_periph_tnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNPR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tnpr_reg_t hri_pdc_get_PERIPH_TNPR_reg(const void *const         hw,
                                                                    hri_pdc_periph_tnpr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TNPR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TNPR_reg(const void *const hw, hri_pdc_periph_tnpr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNPR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TNPR_reg(const void *const hw, hri_pdc_periph_tnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNPR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TNPR_reg(const void *const hw, hri_pdc_periph_tnpr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNPR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tnpr_reg_t hri_pdc_read_PERIPH_TNPR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_TNPR;
}

static inline void hri_pdc_set_PERIPH_TNCR_TXNCTR_bf(const void *const hw, hri_pdc_periph_tncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNCR |= PDC_PERIPH_TNCR_TXNCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tncr_reg_t hri_pdc_get_PERIPH_TNCR_TXNCTR_bf(const void *const         hw,
                                                                          hri_pdc_periph_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TNCR;
	tmp = (tmp & PDC_PERIPH_TNCR_TXNCTR(mask)) >> PDC_PERIPH_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TNCR_TXNCTR_bf(const void *const hw, hri_pdc_periph_tncr_reg_t data)
{
	uint32_t tmp;
	PDC_CRITICAL_SECTION_ENTER();
	tmp = ((Pdc *)hw)->PERIPH_TNCR;
	tmp &= ~PDC_PERIPH_TNCR_TXNCTR_Msk;
	tmp |= PDC_PERIPH_TNCR_TXNCTR(data);
	((Pdc *)hw)->PERIPH_TNCR = tmp;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TNCR_TXNCTR_bf(const void *const hw, hri_pdc_periph_tncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNCR &= ~PDC_PERIPH_TNCR_TXNCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TNCR_TXNCTR_bf(const void *const hw, hri_pdc_periph_tncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNCR ^= PDC_PERIPH_TNCR_TXNCTR(mask);
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tncr_reg_t hri_pdc_read_PERIPH_TNCR_TXNCTR_bf(const void *const hw)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TNCR;
	tmp = (tmp & PDC_PERIPH_TNCR_TXNCTR_Msk) >> PDC_PERIPH_TNCR_TXNCTR_Pos;
	return tmp;
}

static inline void hri_pdc_set_PERIPH_TNCR_reg(const void *const hw, hri_pdc_periph_tncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNCR |= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tncr_reg_t hri_pdc_get_PERIPH_TNCR_reg(const void *const         hw,
                                                                    hri_pdc_periph_tncr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_TNCR;
	tmp &= mask;
	return tmp;
}

static inline void hri_pdc_write_PERIPH_TNCR_reg(const void *const hw, hri_pdc_periph_tncr_reg_t data)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNCR = data;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_clear_PERIPH_TNCR_reg(const void *const hw, hri_pdc_periph_tncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNCR &= ~mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pdc_toggle_PERIPH_TNCR_reg(const void *const hw, hri_pdc_periph_tncr_reg_t mask)
{
	PDC_CRITICAL_SECTION_ENTER();
	((Pdc *)hw)->PERIPH_TNCR ^= mask;
	PDC_CRITICAL_SECTION_LEAVE();
}

static inline hri_pdc_periph_tncr_reg_t hri_pdc_read_PERIPH_TNCR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_TNCR;
}

static inline bool hri_pdc_get_PERIPH_PTSR_RXTEN_bit(const void *const hw)
{
	return (((Pdc *)hw)->PERIPH_PTSR & PDC_PERIPH_PTSR_RXTEN_Msk) > 0;
}

static inline bool hri_pdc_get_PERIPH_PTSR_TXTEN_bit(const void *const hw)
{
	return (((Pdc *)hw)->PERIPH_PTSR & PDC_PERIPH_PTSR_TXTEN_Msk) > 0;
}

static inline bool hri_pdc_get_PERIPH_PTSR_RXCBEN_bit(const void *const hw)
{
	return (((Pdc *)hw)->PERIPH_PTSR & PDC_PERIPH_PTSR_RXCBEN_Msk) > 0;
}

static inline bool hri_pdc_get_PERIPH_PTSR_TXCBEN_bit(const void *const hw)
{
	return (((Pdc *)hw)->PERIPH_PTSR & PDC_PERIPH_PTSR_TXCBEN_Msk) > 0;
}

static inline bool hri_pdc_get_PERIPH_PTSR_ERR_bit(const void *const hw)
{
	return (((Pdc *)hw)->PERIPH_PTSR & PDC_PERIPH_PTSR_ERR_Msk) > 0;
}

static inline hri_pdc_periph_ptsr_reg_t hri_pdc_get_PERIPH_PTSR_reg(const void *const         hw,
                                                                    hri_pdc_periph_ptsr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Pdc *)hw)->PERIPH_PTSR;
	tmp &= mask;
	return tmp;
}

static inline hri_pdc_periph_ptsr_reg_t hri_pdc_read_PERIPH_PTSR_reg(const void *const hw)
{
	return ((Pdc *)hw)->PERIPH_PTSR;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_PDC_G55_H_INCLUDED */
#endif /* _SAMG55_PDC_COMPONENT_ */

/**
 * \file
 *
 * \brief MEM2MEM related functionality.
 *
 * Copyright (C) 2016 - 2017 Atmel Corporation. All rights reserved.
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

#include <hpl_dma.h>
#include <utils.h>
#include <hpl_mem2mem_config.h>

#if CONF_MEM2MEM_ENABLE
/* Array containing callbacks for DMAC channels */
static struct _dma_resource _resources;

/**
 * \brief Initialize DMAC
 */
int32_t _dma_init(void)
{
	hri_mem2mem_write_MR_reg(MEM2MEM, CONF_MEM2MEM_MR_TSIZE);
	NVIC_DisableIRQ(MEM2MEM_IRQn);
	NVIC_ClearPendingIRQ(MEM2MEM_IRQn);

	return ERR_NONE;
}

/**
 * \brief Enable/disable DMA interrupt
 */
void _dma_set_irq_state(const uint8_t channel, const enum _dma_callback_type type, const bool state)
{
	(void)channel;
	/* Ignore channel since currently only MEM2MEM */

	if (DMA_TRANSFER_COMPLETE_CB == type) {
		hri_mem2mem_write_IMR_RXEND_bit(MEM2MEM, state);
	}

	/* Not support DMA_TRANSFER_ERROR_CB */
}

int32_t _dma_set_destination_address(const uint8_t channel, const void *const dst)
{
	(void)channel;
	hri_mem2mem_write_RPR_reg(MEM2MEM, (uint32_t)dst);

	return ERR_NONE;
}

int32_t _dma_set_source_address(const uint8_t channel, const void *const src)
{
	(void)channel;
	hri_mem2mem_write_TPR_reg(MEM2MEM, (uint32_t)src);

	return ERR_NONE;
}

int32_t _dma_srcinc_enable(const uint8_t channel, const bool enable)
{
	(void)channel;
	if (enable == false) {
		/* The transmit channel buffer size must be equal to the
		   receive channel buffer size */
		return ERR_UNSUPPORTED_OP;
	}

	return ERR_NONE;
}

int32_t _dma_set_data_amount(const uint8_t channel, const uint32_t amount)
{
	(void)channel;

	hri_mem2mem_write_TCR_reg(MEM2MEM, amount);
	hri_mem2mem_write_RCR_reg(MEM2MEM, amount);
	return ERR_NONE;
}

int32_t _dma_enable_transaction(const uint8_t channel, const bool software_trigger)
{
	(void)channel;

	if (software_trigger) {
		hri_mem2mem_write_PTCR_reg(MEM2MEM, MEM2MEM_PTCR_RXTEN | MEM2MEM_PTCR_TXTEN);

		NVIC_EnableIRQ(MEM2MEM_IRQn);
	} else {
		hri_mem2mem_write_PTCR_reg(MEM2MEM, MEM2MEM_PTCR_TXTDIS | MEM2MEM_PTCR_RXTDIS);
	}

	return ERR_NONE;
}

int32_t _dma_get_channel_resource(struct _dma_resource **resource, const uint8_t channel)
{
	*resource = &_resources;
	/* SAMG MEM2MEM PDC Channel Number is 28 */
	(void)channel;

	return ERR_NONE;
}

/**
 * \internal MEM2MEM interrupt handler
 */
void MEM2MEM_Handler(void)
{
	if (hri_mem2mem_get_ISR_RXEND_bit(MEM2MEM) && (hri_mem2mem_read_TCR_reg(MEM2MEM) == 0)) {
		NVIC_DisableIRQ(MEM2MEM_IRQn);
		_resources.dma_cb.transfer_done(&_resources);
	}
}

#endif /* CONF_MEM2MEM_ENABLE */

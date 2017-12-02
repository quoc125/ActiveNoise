/**
 * \file
 *
 * \brief SAM Two-Wire Interface
 *
 * Copyright (C) 2016-2017 Atmel Corporation. All rights reserved.
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

#include <hpl_i2c_m_sync.h>
#include <hpl_twi_config.h>
#include <utils.h>
#include <utils_assert.h>

/**
 * \internal Set baudrate for TWI
 *
 * \param[in] hw       TWI Base Address
 * \param[in] clk      TWI peripheral clock rate in HZ
 * \param[in] baudrate TWI I2C baudrate in HZ
 * \param[in] src      TWI CWGR_BRSRCCLK (Bit Rate Source Clock)
 *                     0: PERIPH_CLK, 1: PMC_PCK
 */
static int32_t _twi_set_baudrate(void *const hw, uint32_t clk, uint32_t baudrate, uint32_t src);

/**
 * \internal Retrieve I2C Master Sync configuration instance
 *
 * \param[in] hw The pointer of TWI hardware instance
 *
 * \return The I2C Master Sync configuration instance
 */
static const struct _i2cm_sync_cfg *_get_i2cm_sync_cfg(void *hw);

/**
 * \internal I2C Master Sync read operation
 *
 * \param[in] dev The pointer of I2C Master instance
 * \param[in] msg The pointer of I2C message struct
 *
 * \return The status of the operation
 * \retval ERR_NONE Operation sucessfully
 */
static inline int32_t _i2c_m_sync_read(struct _i2c_m_sync_device *const dev, struct _i2c_m_msg *msg);

/**
 * \internal I2C Master Sync write operation
 *
 * \param[in] dev The pointer of I2C Master instance
 * \param[in] msg The pointer of I2C message struct
 *
 * \return The status of the operation
 * \retval ERR_NONE Operation sucessfully
 */
static inline int32_t _i2c_m_sync_write(struct _i2c_m_sync_device *const dev, struct _i2c_m_msg *msg);

/**
 * \brief TWI I2C Master Sync configuration Type
 */
struct _i2cm_sync_cfg {
	void *              hw; /*!< instance of TWI */
	hri_twi_cr_reg_t    ctrl;
	hri_twi_smbtr_reg_t smbtr;
	hri_twi_filtr_reg_t filtr;
	hri_twi_cwgr_reg_t  cwgr;
	uint32_t            clkrate;
};

/**
 * \brief Array of I2C Master Sync configurations
 */
static const struct _i2cm_sync_cfg _i2cm_sync_cfgs[1] = {
    {(void *)TWI3,
     CONF_TWI3_CR_REG,
     CONF_TWI3_SMBTR_REG,
     CONF_TWI3_FILTR_REG,
     CONF_TWI3_CWGR_REG,
     CONF_TWI3_FREQUENCY / 1000},
};

/**
 * \berif Retrieve I2C Master Sync configuration instance
 */
static const struct _i2cm_sync_cfg *_get_i2cm_sync_cfg(void *hw)
{
	uint8_t i;

	for (i = 0; i < ARRAY_SIZE(_i2cm_sync_cfgs); i++) {
		if (_i2cm_sync_cfgs[i].hw == hw) {
			return &(_i2cm_sync_cfgs[i]);
		}
	}
	return NULL;
}

int32_t _i2c_m_sync_init(struct _i2c_m_sync_device *const dev, void *const hw)
{
	ASSERT(dev && hw);

	const struct _i2cm_sync_cfg *cfg;

	/* Get TWI base address from FLEXCOM */
	dev->hw = (void *)(((uint32_t)hw) + 0x600U);
	cfg     = _get_i2cm_sync_cfg(dev->hw);

	hri_flexcom_write_MR_reg(hw, FLEXCOM_MR_OPMODE_TWI);

	hri_twi_write_CR_reg(dev->hw, cfg->ctrl);
	hri_twi_write_SMBTR_reg(dev->hw, cfg->smbtr);
	hri_twi_write_FILTR_reg(dev->hw, cfg->filtr);
	hri_twi_write_CWGR_reg(dev->hw, cfg->cwgr);

	return ERR_NONE;
}

int32_t _i2c_m_sync_deinit(struct _i2c_m_sync_device *const dev)
{
	ASSERT(dev);

	hri_twi_write_CR_reg(dev->hw, TWI_CR_SWRST);
	dev->hw = NULL;

	return ERR_NONE;
}

int32_t _i2c_m_sync_enable(struct _i2c_m_sync_device *const dev)
{
	ASSERT(dev);

	hri_twi_write_CR_reg(dev->hw, TWI_CR_MSEN);

	return ERR_NONE;
}

int32_t _i2c_m_sync_disable(struct _i2c_m_sync_device *const dev)
{
	ASSERT(dev);

	hri_twi_write_CR_reg(dev->hw, TWI_CR_MSDIS);

	return ERR_NONE;
}

int32_t _i2c_m_sync_set_baudrate(struct _i2c_m_sync_device *const dev, uint32_t clkrate, uint32_t baudrate)
{
	ASSERT(dev && baudrate);
	(void)clkrate;

	const struct _i2cm_sync_cfg *cfg = _get_i2cm_sync_cfg(dev->hw);

	return _twi_set_baudrate(
	    dev->hw, cfg->clkrate, baudrate, ((cfg->cwgr & TWI_CWGR_BRSRCCLK_Msk) >> TWI_CWGR_BRSRCCLK_Pos));
}

int32_t _i2c_m_sync_send_stop(struct _i2c_m_sync_device *const dev)
{
	ASSERT(dev && dev->hw);

	hri_twi_write_CR_reg(dev->hw, TWI_CR_STOP);

	return ERR_NONE;
}

int32_t _i2c_m_sync_transfer(struct _i2c_m_sync_device *const dev, struct _i2c_m_msg *msg)
{
	ASSERT(dev && msg);

	if (dev->service.msg.flags & I2C_M_BUSY) {
		return I2C_ERR_BUSY;
	}

	if (msg->flags & I2C_M_RD) {
		return _i2c_m_sync_read(dev, msg);
	} else {
		return _i2c_m_sync_write(dev, msg);
	}
}

static inline int32_t _i2c_m_sync_write(struct _i2c_m_sync_device *const dev, struct _i2c_m_msg *msg)
{
	uint32_t i;
	uint32_t sr;
	int      ret = ERR_NONE;

	msg->flags |= I2C_M_BUSY;

	if (msg->addr & I2C_M_TEN) {
		hri_twi_write_MMR_reg(dev->hw, TWI_MMR_DADR(0x78 | (msg->addr >> 8)) | TWI_MMR_IADRSZ(1));
		hri_twi_write_IADR_reg(dev->hw, msg->addr & 0xff);
	} else {
		hri_twi_write_MMR_reg(dev->hw, TWI_MMR_DADR(msg->addr));
	}

	for (i = 0; i < msg->len; i++) {
		/* Wait for data is transferred from TWI_THR or if NACK is detected */
		do {
			sr = hri_twi_read_SR_reg(dev->hw);
			if (sr & TWI_SR_NACK) {
				ret = I2C_NACK;
				break;
			}
		} while (!(sr & TWI_SR_TXRDY));

		hri_twi_write_THR_reg(dev->hw, msg->buffer[i]);
	}

	if (msg->flags & I2C_M_STOP) {
		hri_twi_write_CR_reg(dev->hw, TWI_CR_STOP);
		while (!hri_twi_get_SR_TXCOMP_bit(dev->hw)) {
		};
	}

	dev->service.msg.flags &= ~I2C_M_BUSY;

	return ret;
}

static inline int32_t _i2c_m_sync_read(struct _i2c_m_sync_device *const dev, struct _i2c_m_msg *msg)
{
	uint32_t i;

	msg->flags |= I2C_M_BUSY;

	if (msg->addr & I2C_M_TEN) {
		hri_twi_write_MMR_reg(dev->hw, TWI_MMR_DADR(0x78 | (msg->addr >> 8)) | TWI_MMR_IADRSZ(1) | TWI_MMR_MREAD);
		hri_twi_write_IADR_reg(dev->hw, msg->addr & 0xff);
	} else {
		hri_twi_write_MMR_reg(dev->hw, TWI_MMR_DADR(msg->addr) | TWI_MMR_MREAD);
	}
	/* In single data byte master read, the START and STOP must both be set */
	hri_twi_write_CR_reg(dev->hw, TWI_CR_START | ((msg->len == 1) ? TWI_CR_STOP : 0));

	for (i = 0; i < msg->len; i++) {
		/* Wait for a byte has been received in TWI_RHR since last read */
		while (!hri_twi_get_SR_RXRDY_bit(dev->hw)) {
		};

		msg->buffer[i] = hri_twi_read_RHR_reg(dev->hw);
		/* In multiple data bytes master read, the STOP must be set after the
		 * last data received but one */
		if (i == (msg->len - 2)) {
			hri_twi_write_CR_reg(dev->hw, TWI_CR_STOP);
		}
	}

	while (!hri_twi_get_SR_TXCOMP_bit(dev->hw)) {
	};
	dev->service.msg.flags &= ~I2C_M_BUSY;

	return ERR_NONE;
}

static int32_t _twi_set_baudrate(void *const hw, uint32_t clk, uint32_t baudrate, uint32_t src)
{
	uint8_t  ckdiv = 0; /* CWGR_CKDIV */
	uint32_t cldiv;     /* CWGR_CLDIV */

	/* Calc CLDIV by CKDIV = 0
	 * src = 0 The peripheral clock is the source clock for bit rate generation
	 * Tlow = 1 / (baudrate * 2) = (CLDIV * CKDIV_val + 3) / clk
	 *
	 * src = 1 The peripheral clock is the source clock for bit rate generation
	 * Tlow = 1 / (baudrate * 2) = (CLDIV * CKDIV_val) / clk
	 */

	cldiv = clk / (baudrate * 2) - (src ? 0 : 3);

	/* cldiv(CWGR_CLDIV) must fit in 8 bits and
	 * ckdiv(CWGR_CKDIV) must fit in 3 bits
	 *
	 * cldiv may overflow 255 by ckdiv = 0 in previous step,
	 * So here will check cldiv, if cldiv > 255 then will loop ckdiv from 1 to
	 * 7 for find a valid cldiv value
	 */
	while ((cldiv > 255) && (ckdiv < 7)) {
		/* Increase clock divider */
		ckdiv++;
		/* Divide cldiv value */
		cldiv = cldiv >> 1;
	}

	if (cldiv > 255) {
		return ERR_INVALID_DATA;
	}
	/* set CWGR(Clock Waveform Generator Register) */
	hri_twi_write_CWGR_reg(hw, TWI_CWGR_CKDIV(ckdiv) | TWI_CWGR_CLDIV(cldiv) | TWI_CWGR_CHDIV(cldiv));

	return ERR_NONE;
}

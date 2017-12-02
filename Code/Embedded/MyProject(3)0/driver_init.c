/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>

struct adc_sync_descriptor  ADC_0;

struct i2c_m_sync_desc I2C_0;

void ADC_0_PORT_init(void)
{

	gpio_set_pin_function(PA17, GPIO_PIN_FUNCTION_OFF);
}

void ADC_0_CLOCK_init(void)
{

	_pmc_enable_periph_clock(ID_ADC);
}

void ADC_0_init(void)
{
	ADC_0_CLOCK_init();
	ADC_0_PORT_init();
	
}

void I2C_0_PORT_init(void)
{

	gpio_set_pin_function(PA4, MUX_PA4A_FLEXCOM3_TWCK);

	gpio_set_pin_function(PA3, MUX_PA3A_FLEXCOM3_TWD);
}

void I2C_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_FLEXCOM3);
}

void I2C_0_init(void)
{
	I2C_0_CLOCK_init();

	//i2c_m_sync_init(&I2C_0, FLEXCOM3);

	I2C_0_PORT_init();
}

void system_init(void)
{
	init_mcu();

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	ADC_0_init();

	I2C_0_init();
}

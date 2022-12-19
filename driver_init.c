/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_adc_base.h>

struct adc_sync_descriptor ADC_10;

void ADC_10_PORT_init(void)
{
	// Disable digital pin circuitry
	gpio_set_pin_direction(PA02, GPIO_DIRECTION_OFF);
	gpio_set_pin_function(PA02, PINMUX_PA02B_ADC_AIN0);
	// Disable digital pin circuitry
	gpio_set_pin_direction(PB02, GPIO_DIRECTION_OFF);
	gpio_set_pin_function(PB02, PINMUX_PB02B_ADC_AIN10);
}

void ADC_10_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, ADC);
	_gclk_enable_channel(ADC_GCLK_ID, CONF_GCLK_ADC_SRC);
}

void ADC_10_init(void)
{
	ADC_10_CLOCK_init();
	ADC_10_PORT_init();
	adc_sync_init(&ADC_10, ADC, (void *)NULL);
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA17

	gpio_set_pin_level(LED_BUILTIN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED_BUILTIN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED_BUILTIN, GPIO_PIN_FUNCTION_OFF);

	ADC_10_init();

	delay_driver_init();
}

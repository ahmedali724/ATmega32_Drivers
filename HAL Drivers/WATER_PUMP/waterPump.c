/*
 ============================================================================
 Name        : waterPump.c
 Module Name : Water Pump
 Author      : Ahmed Ali
 Date        : 26 Apr 2024
 Description : Source file for the water pump driver
 ============================================================================
 */

#include "gpio.h"
#include "waterPump.h"
#include "common_macros.h"

/*
 * Description :
 * 1. The Function responsible for setup the direction for the water pump pin through the GPIO driver.
 * 2. Stop the water pump at the beginning through the GPIO driver.
 */
void WaterPump_init(void)
{
	/* Setup the water pump pin as an output pin */
	GPIO_setupPinDirection(WATER_PUMP_PORTID, WATER_PUMP_PINID, PIN_OUTPUT);
	/* Turn off the water pump at the beginning */
	GPIO_writePin(WATER_PUMP_PORTID, WATER_PUMP_PINID, LOGIC_LOW);
}

/*
 * Description :
 * Function responsible for changing the state of water pump(ON or OFF).
 */
void WaterPump_states(WaterPump_State state)
{
	if (state == ON)
	{
		/* Turn on the water pump */
		GPIO_writePin(WATER_PUMP_PORTID, WATER_PUMP_PINID, LOGIC_HIGH);
	}
	else
	{
		/* Turn on the water pump */
		GPIO_writePin(WATER_PUMP_PORTID, WATER_PUMP_PINID, LOGIC_LOW);
	}
}

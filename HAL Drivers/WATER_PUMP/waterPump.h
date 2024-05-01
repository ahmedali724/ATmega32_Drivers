/*
 ============================================================================
 Name        : waterPump.h
 Module Name : Water Pump
 Author      : Ahmed Ali
 Date        : 26 Apr 2024
 Description : Header file for the water pump driver
 ============================================================================
 */

#ifndef WATERPUMP_H_
#define WATERPUMP_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define WATER_PUMP_PORTID		PORTC_ID
#define WATER_PUMP_PINID  		PIN4_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	OFF, ON
} WaterPump_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * 1. The Function responsible for setup the direction for the water pump pin through the GPIO driver.
 * 2. Stop the water pump at the beginning through the GPIO driver.
 */
void WaterPump_init(void);

/*
 * Description :
 * Function responsible for changing the state of water pump(ON or OFF).
 */
void WaterPump_states(WaterPump_State state);

#endif /* WATERPUMP_H_ */

/*
 ============================================================================
 Name        : soilSensor.c
 Module Name : Soil Sensor
 Author      : Ahmed Ali
 Date        : 26 Apr 2024
 Description : Source file for the soil sensor driver
 ============================================================================
 */

#include "soilSensor.h"
#include "adc.h"
#include "std_types.h"

/*
 * Description :
 * Function responsible for getting the digital value of soil sensor read.
 */
uint16 SoilSensor_getValue(void)
{
	uint16 adcValue = 0;
	adcValue = ADC_readChannel(SENSOR_CHANNEL_ID);
	return adcValue;
}

/*
 ============================================================================
 Name        : soilSensor.h
 Module Name : Soil Sensor
 Author      : Ahmed Ali
 Date        : 26 Apr 2024
 Description : Header file for the soil sensor driver
 ============================================================================
 */

#ifndef SOILSENSOR_H_
#define SOILSENSOR_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         0

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for getting the digital value of soil sensor read.
 */
uint16 SoilSensor_getValue(void);

#endif /* SOILSENSOR_H_ */

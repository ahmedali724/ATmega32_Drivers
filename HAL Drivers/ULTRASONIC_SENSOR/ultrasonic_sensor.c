/*
 ============================================================================
 Name        : ultrasonic_sensor.c
 Module Name : ULTRASONIC SENSORs
 Author      : Ahmed Ali
 Date        : 12 Oct 2023
 Description : Source file file for the Ultrasonic Sensor driver
 ============================================================================
 */

#include "icu.h"  /* To use ICU driver function */
#include "gpio.h" /* To use setup direction function */
#include "ultrasonic_sensor.h"
#include <util/delay.h> /* To use _delay_us in Ultrasonic_Trigger function */

static uint8 g_edgeCount = 0;
static uint16 g_echoTime = 0;

/*
 * Description :
 * 1. Initialize the ICU driver as required.
 * 2. Setup the ICU call back function.
 * 3. Setup the direction for the trigger pin as output pin through the GPIO driver.
 */
void Ultrasonic_init(void)
{
	/* Setup the trigger pin direction as output */
	GPIO_setupPinDirection(TRIGGER_PORT_ID, TRIGGER_PIN_ID, PIN_OUTPUT);

	/* Configuration type of ICU with F_CPU/8 and raising edge  */
	ICU_ConfigType ICU_config =
		{F_CPU_8, RAISING};

	/* Call the initialization function */
	ICU_init(&ICU_config);

	/* Setup the call back function which be handled each interrupt */
	ICU_setCallBack(Ultrasonic_edgeProcessing);
}

/*
 * Description :
 * Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_Trigger(void)
{
	/*  Transmit trigger pulse of at least 10 us to the HC-SR04 Trig Pin */
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_HIGH);
	/* 20 us to ensure that the trigger pulse has been sent successfully */
	_delay_us(TRIGGER_DELAY_VALUE);
	GPIO_writePin(TRIGGER_PORT_ID, TRIGGER_PIN_ID, LOGIC_LOW);
}

/*
 * Description :
 * 1. Send the trigger pulse by using Ultrasonic_Trigger function.
 * 2. Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_readDistance(void)
{
	uint16 distance;
	/* Send the trigger pulse to HC-SR04 Trig Pin */
	Ultrasonic_Trigger();

	/*
	 * Calculation details:
	 * Sound velocity = 340.00 m/s = 34000 cm/s
	 * The distance of Object (in cm) = (340000*echoTime)/2 = 17000 * echoTime
	 * F_CPU/8 for timer frequency.
	 * Then time to execute 1 instruction is 1 us.
	 * Distance = 17000 x (echoTime) x 1 x 10^-6 cm = 0.017 x (echoTime) cm = (echoTime) / 58.8 cm
	 */
	distance = g_echoTime / 58.8;
	return distance;
}

/*
 * Description :
 * 1. This is the call back function called by the ICU driver.
 * 2. This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if (g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if (g_edgeCount == 2)
	{
		/* Store the High time value */
		g_echoTime = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
		/* For the next distance measurements operation */
		g_edgeCount = 0;
	}
}

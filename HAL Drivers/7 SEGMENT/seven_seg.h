/*
 ============================================================================
 File Name   : seven_seg.h
 Description : Header file for the 7 segment driver
 Module      : 7 segment
 Author      : Ahmed Ali
 Date        : 26 Sept 2023
 ============================================================================
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * If implement using decoder, then using this define
 *
 * #define DECODER_CONFIG
 */

#ifndef DECODER_CONFIG

/* 7 segment Port Configurations */
#define SEVEN_SEGMENT_PORT          	PORTA_ID

#define SEVEN_SEGMENT_A_PIN_ID      	PIN1_ID
#define SEVEN_SEGMENT_B_PIN_ID      	PIN2_ID
#define SEVEN_SEGMENT_C_PIN_ID			PIN3_ID
#define SEVEN_SEGMENT_D_PIN_ID			PIN4_ID
#define SEVEN_SEGMENT_E_PIN_ID		    PIN5_ID
#define SEVEN_SEGMENT_F_PIN_ID		    PIN6_ID
#define SEVEN_SEGMENT_G_PIN_ID		    PIN7_ID

#define SEVEN_SEGMENT_ENABLE_PORT       PORTC_ID

#define SEVEN_SEGMENT_ENABLE_PIN_ID		PIN6_ID

#endif

#ifdef DECODER_CONFIG
/* Decoder Port Configurations */
#define DECODER_PORT            PORTA_ID

#define DECODER_A_PIN_ID        PIN1_ID
#define DECODER_B_PIN_ID        PIN2_ID
#define DECODER_C_PIN_ID		PIN3_ID
#define DECODER_D_PIN_ID		PIN4_ID

#endif
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Display a specific number in 7 segment
 */
void SEVENSEGMENT_diplayNumber(uint8 number);

/*
 * Description :
 * function to initialization 7 segment
 */
void SEVENSEGMENT_init(void);

#endif /* SEVEN_SEG_H_ */

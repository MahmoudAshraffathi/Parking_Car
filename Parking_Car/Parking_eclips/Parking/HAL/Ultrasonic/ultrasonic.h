/*
 * ultrasonic.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

#include "../../MCAL/ICU/icu.h"
#include "../../MCAL/GPIO/gpio.h"
#include <avr/delay.h>

#define PORT_TRIGGER  PORTD_ID
#define PIN_TRIGGER  PIN7_ID

#define PORT_ECHO  PORTD_ID
#define PIN_ECHO   PIN6_ID

extern uint8 g_edgeCount ;
extern uint16 g_timeHigh ;


uint8 Ultrasonic_readDistance(void);
void Ultrasonic_Trigger(void);
void Ultrasonic_init(void);
 void Ultrasonic_edgeProcessing(void);







#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */

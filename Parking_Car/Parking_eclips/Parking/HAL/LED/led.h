/*
 * LED.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef LED_H_
#define LED_H_
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/std_types.h"

#define LED_PORT     PORTC_ID

#define LED1_PIN      PIN0_ID
#define LED2_PIN      PIN1_ID
#define LED3_PIN      PIN2_ID
#define POSTIVE_CONNECTTION
//#define NEGATIVE_CONNECTTION
typedef enum{
	LED1,
	LED2,
	LED3
} LED_ID;

void LEDS_Init(void);
void LED_On(LED_ID id);
void LED_Off(LED_ID id);



#endif /* LED_H_ */

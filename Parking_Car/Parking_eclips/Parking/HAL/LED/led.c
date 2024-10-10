/*
 * LED.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#include "../../HAL/LED/led.h"

void LEDS_Init(void){
	/*set the direction*/
	GPIO_setupPinDirection(LED_PORT,LED1_PIN,PIN_OUTPUT);  /*RED*/
	GPIO_setupPinDirection(LED_PORT,LED2_PIN,PIN_OUTPUT);  /*Green*/
	GPIO_setupPinDirection(LED_PORT,LED3_PIN,PIN_OUTPUT);  /*Blue*/
	/*set the initial configuration*/
#ifdef POSTIVE_CONNECTTION
	GPIO_writePin(LED_PORT,LED1_PIN,LOGIC_LOW);
	GPIO_writePin(LED_PORT,LED2_PIN,LOGIC_LOW);
	GPIO_writePin(LED_PORT,LED3_PIN,LOGIC_LOW);
#elif NEGATIVE_CONNECTTION
	GPIO_writePin(LED_PORT,LED1_PIN,LOGIC_HIGH);
	GPIO_writePin(LED_PORT,LED2_PIN,LOGIC_HIGH);
	GPIO_writePin(LED_PORT,LED3_PIN,LOGIC_HIGH);
#endif

}

void LED_On(LED_ID id){
	switch (id) {
		case LED1:
#ifdef POSTIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED1_PIN,LOGIC_HIGH);
#elif NEGATIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED1_PIN,LOGIC_LOW);
#endif
			break;
		case LED2:
#ifdef POSTIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED2_PIN,LOGIC_HIGH);
#elif NEGATIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED2_PIN,LOGIC_LOW);
#endif

			break;
		case LED3:
#ifdef POSTIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED3_PIN,LOGIC_HIGH);
#elif NEGATIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED3_PIN,LOGIC_LOW);
#endif
			break;
		default:
			break;
	}
}

void LED_Off(LED_ID id){
	switch (id) {
			case LED1:
#ifdef POSTIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED1_PIN,LOGIC_LOW);
#elif NEGATIVE_CONNECTTION
			GPIO_writePin(LED_PORT,LED1_PIN,LOGIC_HIGH);
#endif
				break;
			case LED2:
#ifdef POSTIVE_CONNECTTION
				GPIO_writePin(LED_PORT,LED2_PIN,LOGIC_LOW);
#elif NEGATIVE_CONNECTTION
				GPIO_writePin(PORTB_ID,LED2_PIN,LOGIC_HIGH);
#endif
				break;
			case LED3:
#ifdef POSTIVE_CONNECTTION
				GPIO_writePin(LED_PORT,LED3_PIN,LOGIC_LOW);
#elif NEGATIVE_CONNECTTION
				GPIO_writePin(PORTB_ID,LED3_PIN,LOGIC_HIGH);
#endif
				break;
			default:
				break;
		}
}

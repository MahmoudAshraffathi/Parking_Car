/*
 * ultrasonic.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Mahmoud Ashraf
 */

#include "ultrasonic.h"

uint8 g_edgeCount = 0;  // counter use in Edge Processing
uint16 g_timeHigh = 0;  // period from first Rising and FiSrst Falling

void Ultrasonic_init(void) {
	ICU_ConfigType UltraSoinc = { F_CPU_8, RAISING };
	GPIO_setupPinDirection(PORT_TRIGGER, PIN_TRIGGER, PIN_OUTPUT); // Set the direction for the trigger pin as output
	ICU_init(&UltraSoinc);    // Initialize the ICU driver
	ICU_setCallBack(Ultrasonic_edgeProcessing);  //Set up the ICU callback function.

}
// to generate trigger signal
void Ultrasonic_Trigger(void) {
	GPIO_writePin(PORT_TRIGGER, PIN_TRIGGER, LOGIC_LOW);
	_delay_us(10);
	GPIO_writePin(PORT_TRIGGER, PIN_TRIGGER, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORT_TRIGGER, PIN_TRIGGER, LOGIC_LOW);
	_delay_us(10);

}

uint8 Ultrasonic_readDistance(void) {
	uint16 Distance = 0 ;
	Ultrasonic_Trigger(); // Send the trigger pulse by using the Ultrasonic_Trigger function.
	Ultrasonic_edgeProcessing(); //Start the measurement process to Calculate the period of the reflected signal.
	Distance = ((uint8) ((uint16)g_timeHigh / 118)) ;
	return Distance ;
}

void Ultrasonic_edgeProcessing(void) {
	/* This is the call-back function */

	g_edgeCount++;
	if (g_edgeCount == 1) {
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	} else if (g_edgeCount == 2) {
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
		ICU_clearTimerValue();
		g_edgeCount = 0 ;

	}

}

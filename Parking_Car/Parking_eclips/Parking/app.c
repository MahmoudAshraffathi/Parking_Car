/*
 * app.c
 *
 *  Created on: Oct 9, 2024
 *      Author: Mahmoud Ashraf
 */

#include "app.h"
//===============================================================
volatile uint16 distance = 0;  // Distance between Sensor and Object

int main(void) {
// Initialization
	LEDS_Init();
	Ultrasonic_init();
	LCD_init();
	Buzzer_init();
	sei(); // Enable Globale Interrupt
//===================welcome Message==============================
	LCD_displayString("ENG MohamedTarek");
	LCD_displayStringRowColumn(1, 0, " Mahmoud Ashraf");
	_delay_ms(2000);
	LCD_clearScreen();
//================================================================
	while (1) {
		distance = Ultrasonic_readDistance(); // Always calculate distance
		LCD_displayStringRowColumn(0, 1, "Distance: "); // to dispaly on lcd
// to handel displaying Distance
		if (distance >= 100) {
			LCD_intgerToString(distance);
			LCD_displayString("cm");
		} else {
			LCD_intgerToString(distance);
			LCD_displayString("cm");
			LCD_displayCharacter(' ');
		}
//====================Handel an LEDS Indicator=============================
		if (distance) {      // Handel first start for Sensor
			if (distance > 20) {
				Buzzer_Off();
				LED_Off(LED1);
				LED_Off(LED2);
				LED_Off(LED3);
				LCD_displayStringRowColumn(1, 5, "    ");
				Buzzer_Off();
			} else if (distance <= 20 && distance >= 16) {
				LED_On(LED1);
				LED_Off(LED2);
				LED_Off(LED3);
				LCD_displayStringRowColumn(1, 5, "    ");
				Buzzer_Off();
			} else if (distance <= 15 && distance >= 11) {
				LED_On(LED1);
				LED_On(LED2);
				LED_Off(LED3);
				LCD_displayStringRowColumn(1, 5, "    ");
				Buzzer_Off();
			} else if (distance <= 10 && distance >= 6) {
				_delay_ms(100);
				LED_On(LED1);
				LED_On(LED2);
				LED_On(LED3);
				Buzzer_Off();
				LCD_displayStringRowColumn(1, 5, "    ");
			} else if (distance <= 5) {
				Buzzer_On();
				LCD_displayStringRowColumn(1, 5, "STOP");
				LED_Off(LED1);
				LED_Off(LED2);
				LED_Off(LED3);
				_delay_ms(200);
				LED_On(LED1);
				LED_On(LED2);
				LED_On(LED3);
				_delay_ms(200);
			}
		} else { //
			_delay_ms(200); // to take his time for setup initialization
		}
	}
	return 0;
}
//===============================END========================================

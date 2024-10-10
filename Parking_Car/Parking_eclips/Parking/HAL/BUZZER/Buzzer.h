/*
 * BUZZER.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Ashraf
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "../../MCAL/GPIO/gpio.h"

#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN  PIN5_ID

void Buzzer_init(void);
void Buzzer_On(void);
void Buzzer_Off(void);


#endif /* BUZZER_H_ */

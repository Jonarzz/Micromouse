/*
 * dioda.c
 *
 *  Created on: 9 gru 2015
 *      Author: varsheim
 */

#include "dioda.h"

uint8_t isButtonPressed(uint8_t button_pin) {
	if(!(PIN(BUTTON_PORT) & button_pin)) {
		_delay_ms(20);

		if(!(PIN(BUTTON_PORT) & button_pin)) {
			return 1;
        }
	}
    
	return 0;
}

void toggleLED(uint8_t LED_pin) {
	PORT(LED_PORT) ^= LED_pin;
}

void interrupt_init() {
	TCCR1B |= (1<<CS10) | (1<<WGM12);
	TIMSK |= (1<<OCIE1A);
	OCR1A = 16000;
}

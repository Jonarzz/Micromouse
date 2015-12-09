/*
 * main.c
 *
 *  Created on: 9 gru 2015
 *      Author: Luke
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "dioda.h"


int main(void){

	DDR(LED_PORT) |= LED_PIN;
	PORT(LED_PORT) |= LED_PIN;

	DDR(BUTTON_PORT) &= ~BUTTON1_PIN;
	DDR(BUTTON_PORT) &= ~BUTTON2_PIN;
	PORT(BUTTON_PORT) |= BUTTON1_PIN;
	PORT(BUTTON_PORT) |= BUTTON2_PIN;

	iJustToggled = 0;
	counter = 1;
	blinking_freq = 500;

	interrupt_init();
	sei();


	while(1){

		if(isButtonPressed(BUTTON1_PIN))
			blinking_freq = 2000;

		if(isButtonPressed(BUTTON2_PIN))
			blinking_freq = 50;

		if(!iJustToggled && (counter % blinking_freq == 0)){
			toggleLED(LED_PIN);
			iJustToggled = 1;

		}
	}
}

ISR(TIMER1_COMPA_vect){ //POWINNO sie wykonac co 1ms
counter++;
iJustToggled = 0;
if(counter > 6000)
	counter = 1;
}
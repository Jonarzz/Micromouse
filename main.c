/*
 * main.c
 *
 *  Created on: 9 gru 2015
 *      Author: varsheim
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "dioda.h"


int main(void) {

	DDR(LED_PORT) |= LED_PIN;
	PORT(LED_PORT) |= LED_PIN;

	DDR(BUTTON_PORT) &= ~BUTTON1_PIN;
	DDR(BUTTON_PORT) &= ~BUTTON2_PIN;
	PORT(BUTTON_PORT) |= BUTTON1_PIN;
	PORT(BUTTON_PORT) |= BUTTON2_PIN;

	justToggled = 0;
	countTime = 0;
	countClicks = 0;
	timeBetweenClicks = 0;
	clickCounter = 0;

	mainCounter = 1;
	maxMainCounter = 6000;
	blinkingFreq = 500;

	interrupt_init();
	sei();

	while (1) {

		if (wasButtonClicked(BUTTON1_PIN)) {
			clickCounter = 0;
			timeBetweenClicks = 0;
			countTime = 0;
			countClicks = 1;
			PORT(LED_PORT) |= LED_PIN;
		}

		if (wasButtonClicked(BUTTON2_PIN)) {
			if (countClicks) {
				if (clickCounter < MAX_NUM_OF_CLICKS) {
					clickCounter++;
				}
				if (clickCounter == 1) {
					countTime = 1;
				}
			}
		}

		if (clickCounter == MAX_NUM_OF_CLICKS) {
			countTime = 0;
			countClicks = 0;
			clickCounter = 0;
		}

		if (countTime || countClicks) {
			continue;
		}

		blinkingFreq = timeBetweenClicks / MAX_NUM_OF_CLICKS;
		maxMainCounter = blinkingFreq * 10;

		if (!justToggled && (mainCounter % blinkingFreq == 0)) {
			toggleLED(LED_PIN);
			justToggled = 1;
		}
	}
}

ISR(TIMER1_COMPA_vect) {
	mainCounter++;
	justToggled = 0;
	if (mainCounter > maxMainCounter) {
		mainCounter = 1;
	}
	if (countTime) {
		timeBetweenClicks++;
	}
}

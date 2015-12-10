/*
 * dioda.h
 *
 *  Created on: 9 gru 2015
 *      Author: varsheim
 */

#ifndef DIODA_H_
#define DIODA_H_

#include <avr/io.h>
#include <util/delay.h>
// Makra upraszczaj¹ce dostêp do portów
// *** PORT
#define PORT(x) XPORT(x)
#define XPORT(x) (PORT##x)
// *** PIN
#define PIN(x) XPIN(x)
#define XPIN(x) (PIN##x)
// *** DDR
#define DDR(x) XDDR(x)
#define XDDR(x) (DDR##x)


//porty na ktorych podlaczone sa rzeczy
#define LED_PORT C
#define LED_PIN 1<<4

#define BUTTON_PORT B
#define BUTTON1_PIN 1<<2
#define BUTTON2_PIN 1<<3

volatile uint16_t counter;
uint16_t blinking_freq;
uint8_t justToggled;

uint8_t isButtonPressed(uint8_t button_pin);
void toggleLED(uint8_t LED_pin);
void interrupt_init();

#endif /* DIODA_H_ */

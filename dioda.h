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
// Makra upraszczajace dostep do portow
// *** DDR - ustawienie wyjscia/wejscia na pinie
#define DDR(x) XDDR(x)
#define XDDR(x) (DDR##x)
// *** PORT - ustawienie stanu niskiego/wysokiego na pinie
#define PORT(x) XPORT(x)
#define XPORT(x) (PORT##x)
// *** PIN - odczytanie stanu niskiego/wysokiego na pinie
#define PIN(x) XPIN(x)
#define XPIN(x) (PIN##x)
// *** P - ogolna definicja pinu i portu, na ktorym sie znajduje (np. PB2, PC4)
#define P(x, y) XP(x, y)
#define XP(x, y) (P##x##y)


//porty na ktorych podlaczone sa rzeczy
#define LED_PORT C
#define LED_PIN 1<<P(LED_PORT, 4)

#define BUTTON_PORT B
#define BUTTON1_PIN 1<<P(BUTTON_PORT, 2)
#define BUTTON2_PIN 1<<P(BUTTON_PORT, 3)

#define BUTTON_DELAY 20

volatile uint16_t counter;
uint16_t blinkingFreq;
uint8_t justToggled;

uint8_t isButtonPressed(uint8_t button_pin);
void toggleLED(uint8_t LED_pin);
void interrupt_init();

#endif /* DIODA_H_ */

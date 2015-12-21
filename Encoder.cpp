/*
 ****************************************************************************
 *  Copyright (c) 2015 Dark Guan <tickel.guan@gmail.com>                    *
 *	This file is part of Ananas.                                            *
 *                                                                          *
 *  Ananas is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by    *
 *  the Free Software Foundation, either version 3 of the License, or       *
 *  (at your option) any later version.                                     *
 *                                                                          *
 *  FreeLSS is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *  GNU General Public License for more details.                            *
 *                                                                          *
 *   You should have received a copy of the GNU General Public License      *
 *   along with FreeLSS.  If not, see <http://www.gnu.org/licenses/>.       *
 ****************************************************************************
*/
/*
 * Encoder.cpp
 *
 *  Created on: 2015年12月14日
 *      Author: Dark
 */
#include "arduino.h"
#include "Ananas.h"

//encoder use interrupt
long encodercount;

volatile bool stateA;
volatile bool stateB;

bool inverseCountDir;

uint8_t increment;

void counter1_C();
void counter2_C();

void initialEncoder() {
	//set all the pins
	pinMode(ENCODER_A, INPUT);
	pinMode(ENCODER_A, INPUT);
	//use the pull-up resistor
	digitalWrite(ENCODER_A, HIGH);
	digitalWrite(ENCODER_B, HIGH);

	//CHANGE
	attachInterrupt(0, counter1_C, CHANGE); //为A 相添加中断
	attachInterrupt(1, counter2_C, CHANGE); //为B 相添加中断

	encodercount = 0;

	//TODO add EEPROM settings
	inverseCountDir = INV_COUNT_DIR;
	if (inverseCountDir) {
		increment = 1;
	} else {
		increment = -1;
	}
}

//change the count dir
void changeDir() {
	inverseCountDir = !inverseCountDir;
	if (inverseCountDir) {
		increment = 1;
	} else {
		increment = -1;
	}
}

//CHNANGE
void counter1_C() {
	noInterrupts();
	stateA = digitalRead(ENCODER_A);
	stateB = digitalRead(ENCODER_B);
	if (stateA ^ stateB) //state is not same then
			{
		encodercount += increment;
	} else {
		encodercount -= increment;
	}
	interrupts();
}
void counter2_C() {
	noInterrupts();
	stateA = digitalRead(ENCODER_A);
	stateB = digitalRead(ENCODER_B);
	if (!(stateA ^ stateB)) {
		encodercount += increment;
	} else {
		encodercount -= increment;
	}
	interrupts();
}

float getPosition() {
	return float(encodercount / float(ENCODER_COUNTS_PER_UNIT));
}

long getEncodercount() {
	return encodercount;
}

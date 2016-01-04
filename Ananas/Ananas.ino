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
 *  Ananas is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *  GNU General Public License for more details.                            *
 *                                                                          *
 *   You should have received a copy of the GNU General Public License      *
 *   along with Ananas.  If not, see <http://www.gnu.org/licenses/>.       *
 ****************************************************************************
 */

// Do not remove the include below
#include "Ananas.h"
#include "Da.h"
#include "Encoder.h"
#include "stepper.h"

//The setup function is called once at startup of the sketch
bool closeLoop = false;

void serialManager();
void printInformation();

void setup() {
// Add your initialization code here
	Serial.begin(BANDRATE);
	//��ʼ��˳�����Ҫ�����Է�ֹ����ڳ�ʼ����ʱ�򶶶����Լ���������׼�����
	initial_DA();
	initialStepper();
	initialEncoder();

	printInformation();
}

// The loop function is called in an endless loop
void loop() {
//Add your repeated code here
	serialManager();

	if (closeLoop)
		managerDelay();
}

void printInformation() {
	Serial.print("Pulse Count : ");
	Serial.println(getSteps());
	Serial.print("Destination : ");
	Serial.println(getDestination());
	Serial.println();
	Serial.print("Encoder Count : ");
	Serial.println(getEncodercount());
	Serial.print("Positon : ");
	Serial.println(getPosition());
	Serial.println();
	Serial.print("Voltage : ");
	Serial.println(getvol());
	Serial.println();
	Serial.print("Error : ");
	Serial.println(getError());
}

void serialManager() {

	if (Serial.available() > 0) {
		char command = Serial.read();
		char sign;
		switch (command) {
		case 'C':
			closeLoop = !closeLoop;
			Serial.println("Shift CloseLoop");
			break;
		case 'D':
			changeDisableMotor();
			break;
		case 'R':
			sign = Serial.read();
			if (sign == '+')
				step(true);
			else if (sign == '-') {
				step(false);
			}
			break;

		case 'i':
			printInformation();
			break;

		case 'v':

			break;

			//�ı似���͵����
		case 'c':
			sign = Serial.read();
			if (sign == 'e') {
				changeDir();
			} else if (sign == 'd') {
				changeMotorDir();
			}

			break;
		default:
			break;
		}
		sign = 0;
	}

	while (Serial.available() > 0)
		Serial.read();

}

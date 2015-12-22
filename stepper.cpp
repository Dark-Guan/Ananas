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
/*
 * stepper.cpp

 *
 *  Created on: 2015年12月14日
 *      Author: Dark
 */

#include "Ananas.h"
#include "QUN.h"
#include "Encoder.h"
#include "DA.h"

long pulseCount;

long encoderCount;

long error;
uint16_t errorAbs;

bool dirState;
bool enalbeState;

bool invDir;

bool enableDelay = false;

uint16_t delaytime;

//使用比较器中断
QUN M;

//define
void pulse();
void stepastep();
void managerDalaytime(long error);
void mapThepin();

void initialStepper() {
	//set input pins
	//在这里要用到光耦的时候 需要上拉 电阻
	pinMode(DIRPIN, INPUT);
	pinMode(STEPPIN, INPUT);
	pinMode(ENABLEPIN, INPUT);

	//set output pins
	pinMode(STEP_DIR, OUTPUT);
	pinMode(STEP_STEP, OUTPUT);
	pinMode(STEP_ENABLE, OUTPUT);

	//初始化锁紧电机
//	digitalWrite(STEP_ENABLE, LOW);
	//把step端口置为高位
	digitalWrite(STEP_STEP, HIGH);

	//add interrupt
	//TODO 需要结合上位机判断，脉冲初始的是高还是低电平
	M.attachInterrupt(pulse, M_FALLING); //D7
	//对下降沿计数
	// M_CHANGE 当引脚电平发生改变时，触发中断
	// M_RISING 当引脚由低电平变为高电平时，触发中断
	// M_FALLING 当引脚由高电平变为低电平时，触发中断
	pulseCount = 0;
	//
	invDir = INV_DIR;

	delaytime = DELAYTIME;
	mapThepin();

}

//只在调试的时候使用
void changeMotorDir() {
	invDir = !invDir;
}

void pulse() {
//对上位机脉冲进行计数
//同时实时发生给步进驱动
	noInterrupts();

	digitalWrite(STEP_ENABLE, LOW);

	dirState = digitalRead(DIRPIN);
	//输出脉冲
	if (dirState) {
		digitalWrite(STEP_DIR, invDir);
		pulseCount++;
		stepastep();
	} else {
		digitalWrite(STEP_DIR, !invDir);
		pulseCount--;
		stepastep();
	}
	interrupts();
}

//测试用 转动一圈 检测线路 用来测试电机方向和连线
//实际不使用
void step(bool dir) {
	if (dir) {
		digitalWrite(STEP_DIR, !invDir);
	} else {
		digitalWrite(STEP_DIR, invDir);
	}
	for (int i = 0; i < (MOTOR_STEPS_PER_CIRCLE * DRIVE_SUBDIVE); i++) {
		stepastep();
		delayMicroseconds(DELAYTIME / 2);
	}
}

void stepastep() {
	digitalWrite(STEP_STEP, LOW);
	digitalWrite(STEP_STEP, HIGH);
}

//主要来处理ENABLEPIN
void mapThepin() {
	enalbeState = digitalRead(ENABLEPIN);
	digitalWrite(STEP_ENABLE, enalbeState);
}

float getDestination() {
	return float(pulseCount / float(STEPS_PER_UNIT));
}

long getSteps() {
	return pulseCount;
}

long getError() {
	return error;
}

void managerDelay() {
	encoderCount = getEncodercount();
	error = (encoderCount * STRONG_PURSE_FACTOR - pulseCount);
	errorAbs = abs(error);

//manage the voltage
	managerVoltage(errorAbs);
	managerDalaytime(errorAbs);

	if (errorAbs >= STRONG_PURSE_FACTOR) {
		noInterrupts();
		digitalWrite(STEP_ENABLE, LOW);
		if (error > 0) {
			digitalWrite(STEP_DIR, !invDir);
			stepastep();
		} else {
			digitalWrite(STEP_DIR, invDir);
			stepastep();
		}
		interrupts();
		if (enableDelay)
			delayMicroseconds(delaytime);
	}
//	delayMicroseconds(1000);

}

void managerDalaytime(long error) {
	if (error < (MAXERROR)) {
		enableDelay = true;
		delaytime = DELAYTIME;
	} else {
		enableDelay = true;
		delaytime = MIN_DELAYTIME;	//满足
	}
}

void changeDisableMotor() {
//	mapThepin();
	digitalWrite(STEP_ENABLE, HIGH);
}

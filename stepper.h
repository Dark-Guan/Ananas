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
 * stepper.h
 *
 *  Created on: 2015Äê12ÔÂ8ÈÕ
 *      Author: Dark
 */
#include "configuration.h"

#ifndef STEPPER_H_
#define STEPPER_H_

//extern float destination/;

void initialStepper();

void changeMotorDir();

void step(bool dir);

void stepastep();

void mapThepin();

float getDestination();

long getSteps();

long getError();

void printOUTstate();

void managerDelay();

void managerDalaytime(long error);

void changeDisableMotor();

#endif /* DA_H_ */

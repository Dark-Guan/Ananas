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
 * Da.cpp
 *
 *  Created on: 2015年12月14日
 *      Author: Dark
 */
#include "Da.h"
#include <TLC5615.h>

/*
 *initial the DA,and set a initial voltage
 *avoid the driver shake
 */
TLC5615 DA = TLC5615(DA_DIN, DA_SCLK, DA_CS);

uint16_t maxvol;
uint16_t minvol;
uint16_t volfactor;
uint8_t errorallow;

uint16_t volstate;

void initial_DA() {
	DA.InitTLC5615();
	//TODO 这里要加上从EEPROM里面来获取匹配电机信息的步骤
	//匹配最大电压和最小电压
	//这里要限制最小电压，要不然驱动器会抖

	maxvol = MAX_DA;
	minvol = DA_initial;
	errorallow = MAXERROR;
	volfactor = (maxvol - minvol) / errorallow;

	//initial DA
	DA_SET_V(minvol);	//以最小值初始DA 这个值后期将是从EEPROM里面读取到的
}

/*
 * set the voltage
 */
void DA_SET_V(unsigned int Vol) {
//the voltage is limited
	//the voltage large then
	if (Vol > maxvol) {
		DA.DAConvert(maxvol);
		volstate = maxvol;
	} else if (Vol < minvol) {
		DA.DAConvert(minvol);
		volstate = minvol;
	} else {
		DA.DAConvert(Vol);
		volstate = Vol;	//store state
	}
}

/*
 * adjust the voltage
 */
void managerVoltage(int error) {
//change the voltage base on the difference between the pulse and the encoder count
//max error

	if (error >= errorallow) {
		DA_SET_V(maxvol);
	} else {
		DA_SET_V(minvol + error * volfactor);
	}
}

uint16_t getvol() {
	return volstate;
}

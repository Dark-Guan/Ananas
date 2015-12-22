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
 * configuration.h
 *
 *  Created on: 2015年12月8日
 *      Author: Dark
 */

#include "arduino.h"

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

/*
 * pursue function needed parameter
 */
#define SIMPLE

#ifdef SIMPLE
#define DELAYTIME 10000000//2000 //the end delay time
#define MIN_DELAYTIME 1000//us
#define PURSEFACTOR 10
#define DELAY_FACTOR ((DELAYTIME-MIN_DELAYTIME)/(PURSEFACTOR*MAXERROR))

#define STRONG_PURSE_FACTOR 2 //细分之后的每圈步数，最好是细分之后的编码器每圈计数的倍数 这里是2倍

#endif

/*
 * PINS DIFINE
 * pins map for ananas
 *
 */

//for input
#define DIRPIN 12//6 2015.12.9
#define STEPPIN 7 //interrupt no changes
#define ENABLEPIN 8

#define ENCODER_A 2//interrupt
#define ENCODER_B 3//interrupt
//for arduino's output

//TLC5615 DA
#define DA_DIN 11
#define DA_SCLK 10
#define DA_CS 9

//stepper motor drive
#define STEP_DIR 5 //12
#define STEP_STEP 13
#define STEP_ENABLE 4

//***************************
//end of PINS MAP

#define BANDRATE 115200
#define MYSERIAL Serial

#define STEPS_PER_UNIT 100 //这里要结合机械传动

#define MAXERROR 10//10 //允许多少的脉冲丢失，可以选择在脉冲丢失之后报警

//***************************
/*
 * register the motor
 */
#define MOTOR_STEPS_PER_CIRCLE 200
#define MOTOR_MAX_CURRENT 1.5 //A

//***************************
//end of motor register

//***************************
/*
 * register stepper motor driver
 */

#define INV_DIR true//是否变换电机方向 以适应机械结构
//I_TripMAX = VREF / ( 8 *RS)
#define DRIVENAME A4988
#define DRIVE_REF_VOLTAGE 5 //V
#define DRIVE_MAX_CURRENT 2 //A for motor
#define RS_4988 0.1 //
#define DRIVE_MAX_REF_VOL (MOTOR_MAX_CURRENT/0.7*8*0.1)
#define DRIVE_SUBDIVE 16

//***************************
// End of driver register

/*
 * register DA
 */
#define DA_NAME TLC5615
#define DA_PRECISSION 1024 // V_ref/DA_PRECISSION
#define DA_initial 200//100
#define MAX_DA 280
//***************************
//end of DA register

/*
 * register ENCODER
 */

#define INV_COUNT_DIR true //是否变换计数方向 以适应电机的旋转方向
#define ENCODER_SUBDIVIDE 4
#define ENCODER_RESOLUTION 400
#define ENCODER_COUNTS_PER_CICLE (ENCODER_SUBDIVIDE*ENCODER_RESOLUTION)
#define ENCODER_COUNTS_PER_UNIT (STEPS_PER_UNIT/2)

//***************************
//end of ENCODER register

#endif /* CONFIGURATION_H_ */

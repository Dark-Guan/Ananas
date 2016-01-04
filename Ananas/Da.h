


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
 * Da.h
 *
 *  Created on: 2015��12��8��
 *      Author: Dark
 */
#include "arduino.h"
#include "Ananas.h"


#ifndef DA_H_
#define DA_H_

/*
 * *Created on: 2015��12��8�� ����3:42:03
 *      Author: Dark
 */

void initial_DA();

void DA_SET_V(unsigned int Vol);

void managerVoltage(int error);

uint16_t getvol();

#endif /* DA_H_ */

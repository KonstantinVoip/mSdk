/*
 *  lib/api/mcspi_def.h
 *
 *  Copyright (C) 2013  Iulian Gheorghiu <morgoth.creator@gmail.com>
 *
 *  This file is part of Multiplatform SDK.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MCSPI_DEF_H_
#define MCSPI_DEF_H_
/*#####################################################*/
#include <stdbool.h>
#include "gpio_def.h"
/*#####################################################*/
typedef struct
{
	unsigned char MosiPin;
	unsigned char MisoPin;
	unsigned char SckPin;
	unsigned char Cs0Pin;
	unsigned char Cs1Pin;
	unsigned char Cs2Pin;
	unsigned char Cs3Pin;
	gpio_port_enum MosiPort;
	gpio_port_enum MisoPort;
	gpio_port_enum SckPort;
	gpio_port_enum Cs0Port;
	gpio_port_enum Cs1Port;
	gpio_port_enum Cs2Port;
	gpio_port_enum Cs3Port;
	volatile bool interrupted;
	volatile unsigned char Channel;
	volatile unsigned int BaseAddr;
	volatile unsigned long BaudRate;
	volatile unsigned int BuffSize;
	volatile unsigned int numOfBytes;
	volatile unsigned char McspiNr;
	volatile unsigned char flag;
	volatile unsigned char Priority;
	volatile unsigned char Mode;//_SpiModeRisingSample, _SpiModeRisingSetup, _SpiModeFallingSample, _SpiModeFallingSetup
	volatile unsigned int BytesCnt;
	void *UserData;
	volatile unsigned char* Buff;
	volatile unsigned char* BuffTmp;
	bool DisableCsHandle;
	bool Cpol;
	bool Cpha;
	bool LsbFirst;
	unsigned char WordSize;
	bool Slave;
}Mcspi_t;
/*#####################################################*/
#define new_mcspi Mcspi_t
#ifndef new_
#define new_(structure) (structure*)calloc(1,sizeof(structure));
#endif
#define free_mcspi(address) free(address);
/*#####################################################*/
#endif /* MCSPI_DEF_H_ */
/*#####################################################*/

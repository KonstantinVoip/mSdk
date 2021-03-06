/*
 *  lib/api/mmcsd_api.c
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

#include "mmcsd_api.h"
#include "interface/hs_mmcsd_interface.h"
#include "api/gpio_def.h"
/*#####################################################*/
void mmcsd_init(void *SdStruct, signed int CardDetectPortNr, signed int CardDetectPinNr, new_gpio* StatusLed)
{
	_mmcsd_init(SdStruct, CardDetectPortNr, CardDetectPinNr, StatusLed);
}
/*#####################################################*/
void mmcsd_idle(void *SdStruct)
{
	_mmcsd_idle(SdStruct);
}
/*#####################################################*/
void mmcsd_ioctl(void *_ctrl, unsigned int  command,  unsigned int *buffer)
{
	_mmcsd_ioctl(_ctrl, command,  buffer);
}
/*#####################################################*/
unsigned int mmcsd_write(void *_ctrl, void *ptr, unsigned long block, unsigned int nblks)
{
	return MMCSDWriteCmdSend(_ctrl, ptr, block, nblks);
}
/*#####################################################*/
unsigned int mmcsd_read(void *_ctrl, void *ptr, unsigned long block, unsigned int nblks)
{
	return MMCSDReadCmdSend(_ctrl, ptr, block, nblks);
}
/*#####################################################*/

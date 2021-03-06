/***************************************************************************************/
/*    AM335x Multiplatform SDK test application.                                       */
/*    Copyright (C) 2013  Iulian Gheorghiu.                                            */
/*                                                                                     */
/*    This program is free software; you can redistribute it and/or                    */
/*    modify it under the terms of the GNU General Public License                      */
/*    as published by the Free Software Foundation; either version 2                   */
/*    of the License, or (at your option) any later version.                           */
/*                                                                                     */
/*    This program is distributed in the hope that it will be useful,                  */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of                   */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    */
/*    GNU General Public License for more details.                                     */
/*                                                                                     */
/*    You should have received a copy of the GNU General Public License                */
/*    along with this program.  If not, see <http://www.gnu.org/licenses/>             */
/***************************************************************************************/
#define USE_BACK_SCREEN


#include <math.h>
#include "main.h"

#ifdef test1

#define USE_BACK_SCREEN

#include "board_properties.h"
#include "board_init.h"
#include "interface/lcd_interface.h"
#include "api/timer_api.h"
#include "device/ft5x06.h"

#include "lib/gfx/controls_definition.h"
#include "lib/gfx/buton.h"
#include "lib/gfx/checkbox.h"
#include "lib/gfx/progressbar.h"
#include "lib/gfx/scrollbar.h"
#include "lib/gfx/textbox.h"
#include "lib/gfx/listbox.h"
#include "lib/gfx/window.h"

tWindow *MainWindow = NULL;

#ifdef USE_BACK_SCREEN
tDisplay *BackScreen = NULL;
volatile unsigned char ScreenReRefreshCnt = 0;
#endif

signed int picture_old_x = 0;
signed int picture_old_y = 0;

unsigned int PictureBoxbackBuff[128*96];
/*#####################################################*/
timer(TimerScanTouch);
/*#####################################################*/
void *picture_box_clear_callback(void *data)
{
	tPictureBox* settings = (tPictureBox*)data;
	picturebox_clear(settings);
	unsigned int ClearCnt = 0;
	for(; ClearCnt < 128*96; ClearCnt++)
	{
		PictureBoxbackBuff[ClearCnt] = settings->BackgroundColor;
	}
	return NULL;
}
/*#####################################################*/
void *picture_box_callback_on_down(struct PictureBox_s *settings, tControlCommandData *control_comand)
{
	picture_old_x = control_comand->X;
	picture_old_y = control_comand->Y;
	return NULL;
}
/*#####################################################*/
void *picture_box_refresh_callback(struct PictureBox_s *settings, tControlCommandData *control_comand)
{
	tRectangle dest_rectangle;
	dest_rectangle.sXMin = 0;
	dest_rectangle.sXMax = 128;
	dest_rectangle.sYMin = 0;
	dest_rectangle.sYMax = 96;

	tRectangle src_rectangle;
	src_rectangle.sXMin = 0;
	src_rectangle.sXMax = 128;
	src_rectangle.sYMin = 0;
	src_rectangle.sYMax = 96;

	picturebox_copy_rectangle(settings, PictureBoxbackBuff, 8, 0, &dest_rectangle, &src_rectangle, 128, 96);
	ScreenReRefreshCnt = 2;
	return NULL;
}
/*#####################################################*/
void *picture_box_callback(struct PictureBox_s *settings, tControlCommandData *control_comand)
{
	PictureBoxbackBuff[control_comand->X + (control_comand->Y * 128)] = ClrBlack;
	picture_old_x = control_comand->X;
	picture_old_y = control_comand->Y;

	tRectangle dest_rectangle;
	dest_rectangle.sXMin = 0;
	dest_rectangle.sXMax = 128;
	dest_rectangle.sYMin = 0;
	dest_rectangle.sYMax = 96;

	tRectangle src_rectangle;
	src_rectangle.sXMin = 0;
	src_rectangle.sXMax = 128;
	src_rectangle.sYMin = 0;
	src_rectangle.sYMax = 96;

	picturebox_copy_rectangle(settings, PictureBoxbackBuff, 8, 0, &dest_rectangle, &src_rectangle, 128, 96);
	return NULL;
}
/*#####################################################*/
int main(void) {
    board_init();
/*******************************************************/
    timer_interval(&TimerScanTouch, 20);
/*******************************************************/
#ifdef USE_BACK_SCREEN
    BackScreen = new_(new_screen);
    memcpy((void *)BackScreen, (void *)ScreenBuff, sizeof(new_screen));
    BackScreen->DisplayData = memalign(sizeof(BackScreen->DisplayData[0]) << 3, (BackScreen->Width * BackScreen->Height * sizeof(BackScreen->DisplayData[0])) + 32);
    MainWindow = new_window(BackScreen);
#else
    MainWindow = new_window(ScreenBuff);
#endif
    window_new_buton(MainWindow, Btn1);
    window_new_checkbox(MainWindow, CB1);
    window_new_listbox(MainWindow, ListBox1);
    window_new_progressbar(MainWindow, PBar1);
    window_new_scrollbar(MainWindow, ScrollBar1);
    window_new_textbox(MainWindow, TextBox1);
    window_new_picturebox(MainWindow, PictureBox1);

    /* Enable clear background on refresh */
    PictureBox1->PaintBackground = true;
    /* Set callback's  for picture box*/
    PictureBox1->Events.OnMove.CallBack = picture_box_callback;
    PictureBox1->Events.OnDown.CallBack = picture_box_callback_on_down;
    /* Refresh is used to refresh the picture box when the window or picture box position , size is modified */
    PictureBox1->Events.Refresh.CallBack = picture_box_refresh_callback;

    /* Set callback's  for Btn1*/
    Btn1->Events.OnUp.CallbackData = PictureBox1;
    Btn1->Events.OnUp.CallBack = picture_box_clear_callback;

    /* Clear the picture box */
    picture_box_clear_callback(PictureBox1);

    char TmpStr[30];
    unsigned int CntItems = 0;
    for(CntItems = 0; CntItems < 100; CntItems++)
    {
        sprintf(TmpStr, "%d", CntItems);
        listbox_item_add(ListBox1, TmpStr);
    }
    listbox_item_insert(ListBox1, "Inserted Item", 1);
    listbox_item_remove(ListBox1, 3);


    tControlCommandData control_comand;
    control_comand.Comand = Control_Nop;
    control_comand.CursorCoordonateUsed = true;
/*******************************************************/
/*******************************************************/
    while(1)
    {
        if(timer_tick(&TimerScanTouch))
        {
#ifdef USE_BACK_SCREEN
            if(BackScreen)
#else
            if(ScreenBuff)
#endif
            {
                if(TouchScreen->TouchScreen_Type == TouchScreen_Type_Int) TouchIdle(TouchScreen);
                else if(TouchScreen->TouchScreen_Type == TouchScreen_Type_FT5x06) ft5x06_TouchIdle(TouchScreen);
                memset(&control_comand, 0, sizeof(tControlCommandData));
                control_comand.X = TouchScreen->TouchResponse.x1;
                control_comand.Y = TouchScreen->TouchResponse.y1;
                control_comand.Cursor = (CursorState)TouchScreen->TouchResponse.touch_event1;
                MainWindow->idle(MainWindow, &control_comand);
#ifdef USE_BACK_SCREEN
                if(control_comand.CursorCoordonateUsed) ScreenReRefreshCnt = 2;
                if(ScreenReRefreshCnt)
                {
                    ScreenReRefreshCnt--;
                    screen_copy(ScreenBuff, BackScreen);
                }
#endif
            }
        }
    }
}
#endif

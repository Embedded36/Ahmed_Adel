/*
 * EXINT.c
 *
 *  Created on: Mar 29, 2016
 *      Author: Ahmed
 */
#include "../../../APPLICATION_LAYER/types.h"
#include"../../TIMER0/TIMER0_interface.h"
#include"../EXINT_interface.h"
#include "../../DIO_DRIVER/DIO_interface.h"
#include"../../../HAL_LAYER/KEYPAD/KEYPAD_interface.h"

void APP_voidLED2Toggle(void);
void APP_voidLED1Toggle(void);
void APP_voidLED3Toggle(void);

u8 Flag1 = 0;
u8 Flag2 = 0;
u8 Flag3 = 0;

void APP_voidLED1Toggle(void)
    {
    Flag1 = !Flag1;

    return;
    }

void APP_voidLED2Toggle(void)
    {
    Flag2 = !Flag2;

    return;
    }

void APP_voidLED3Toggle(void)
    {
    Flag3 = !Flag3;

    return;
    }
int main()
    {

    u32 xx;
    u8 yy = 0;

    DIO_u8WritePortDir(DIO_u8PORT2, 0xff);

    Keypad_u16Switches APP_Keypad;

    DIO_voidInit();
    EXINT_voidInit();
    EXINT_ISR0CallBackSet(APP_voidLED1Toggle);
    TIMER_voidINIT();
    KEYPAD_voidInit();

    while (1)
	{

	xx = Timer0_u32read();
	if (xx >= 15600)
	    {
	    yy++;
	    }
	else
	    {

	    }

	//DIO_u8WritePortVal(DIO_u8PORT2, yy);

	APP_Keypad = KEYPAD_Keypad_u16SwitchesRead();

	switch (APP_Keypad.KEYPAD_u16Switches)
	    {

	case (1 << 0):
	    EXINT_ISR0CallBackSet(APP_voidLED1Toggle);
	    break;

	case (1 << 1):
	    EXINT_ISR0CallBackSet(APP_voidLED2Toggle);
	    break;

	case (1 << 2):
	    EXINT_ISR0CallBackSet(APP_voidLED3Toggle);
	    break;

	default:

	    break;

	    }

	if (Flag1 == 0)
	    {
	    DIO_u8WritePinVal(DIO_u8PIN28, DIO_u8HIGH);

	    }
	else
	    {
	    DIO_u8WritePinVal(DIO_u8PIN28, DIO_u8LOW);

	    }

	if (Flag2 == 0)
	    {
	    DIO_u8WritePinVal(DIO_u8PIN29, DIO_u8HIGH);

	    }
	else
	    {
	    DIO_u8WritePinVal(DIO_u8PIN29, DIO_u8LOW);

	    }

	if (Flag3 == 0)
	    {
	    DIO_u8WritePinVal(DIO_u8PIN30, DIO_u8HIGH);

	    }
	else
	    {
	    DIO_u8WritePinVal(DIO_u8PIN30, DIO_u8LOW);

	    }
	}

    return 0;
    }


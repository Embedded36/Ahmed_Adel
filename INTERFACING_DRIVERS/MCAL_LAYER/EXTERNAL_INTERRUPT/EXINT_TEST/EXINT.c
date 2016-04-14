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

static u8 Flag1 = 0;
static u8 Flag2 = 0;
static u8 Flag3 = 0;
static u8 toggle = 0;
static u8 bouncing_flag = 0;
//static u16 bouncing_time = 0;
void APP_voidLED1Toggle(void)
    {
    if (bouncing_flag == 0)
	{
	Flag1 = !Flag1;
	bouncing_flag = 1;
	EXINT_DISABLEINT(EXINT_u8INT0);
	TIMER0_voidReset();
	//bouncing_time = TIMER0_u16readMS();

	}
    else
	{

	}

    return;
    }

void APP_voidLED2Toggle(void)
    {

    if (bouncing_flag == 0)
	{
	Flag2 = !Flag2;
	bouncing_flag = 1;
	EXINT_DISABLEINT(EXINT_u8INT0);
	TIMER0_voidReset();
	//bouncing_time = TIMER0_u16readMS();

	}
    else
	{

	}
    return;
    }

void APP_voidLED3Toggle(void)
    {

    if (bouncing_flag == 0)
	{
	Flag3 = !Flag3;
	bouncing_flag = 1;
	EXINT_DISABLEINT(EXINT_u8INT0);
	TIMER0_voidReset();
	//bouncing_time = TIMER0_u16readMS();
	}
    else
	{

	}
    return;
    }
int main()
    {

    u16 temp;

    Keypad_u16Switches APP_Keypad;

    DIO_voidInit();
    EXINT_voidInit();
    EXINT_ISR0CallBackSet(APP_voidLED1Toggle);
    TIMER0_voidINIT();
    KEYPAD_voidInit();

    while (1)
	{

	temp = TIMER0_u16readMS();

	if (bouncing_flag == 1 && temp > 450)
	    {

	//	DIO_u8WritePinVal(DIO_u8PIN30,1);
	    bouncing_flag = 0;
	    EXINT_ENABLEINT(EXINT_u8INT0);

	    }

	if (temp >= 500)
	    {
	    toggle = !toggle;
	    TIMER0_voidReset();
	    }
	else
	    {

	    }

	APP_Keypad = KEYPAD_Keypad_u16SwitchesRead();

	switch (APP_Keypad.KEYPAD_u16Switches)
	    {

	case (1 << 1):
	    EXINT_ISR0CallBackSet(APP_voidLED1Toggle);
	   // DIO_u8WritePinVal(DIO_u8PIN29, 1);

	    break;

	case (1 << 2):
	    EXINT_ISR0CallBackSet(APP_voidLED2Toggle);
	   // DIO_u8WritePinVal(DIO_u8PIN30, 1);

	    break;

	case (1 << 3):
	    EXINT_ISR0CallBackSet(APP_voidLED3Toggle);
	   // DIO_u8WritePinVal(DIO_u8PIN31, 1);

	    break;

	default:
//	    DIO_u8WritePinVal(DIO_u8PIN31, 0);
//	    DIO_u8WritePinVal(DIO_u8PIN30, 0);
//	    DIO_u8WritePinVal(DIO_u8PIN29, 0);

	    break;

	    }

	DIO_u8WritePinVal(DIO_u8PIN29, Flag1 && toggle);
	DIO_u8WritePinVal(DIO_u8PIN30, Flag2 && toggle);
	DIO_u8WritePinVal(DIO_u8PIN31, Flag3 && toggle);

	}
    return 0;
    }

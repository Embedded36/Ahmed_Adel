/*
 * Timer0_test1.c
 *
 *  Created on: Apr 15, 2016
 *      Author: Ahmed
 */
#include"../../../Shared_Libraries/types.h"
#include "../../../Shared_Libraries/interrupt.h"
#include"../TIMER0_interface.h"
#include"../../DIO_DRIVER/DIO_interface.h"

u8 flag = 0;

u8 flag1 = 0;

void led(void)
    {

    flag = ~flag;

    DIO_u8WritePortVal(DIO_u8PORT0, flag);


    flag1 = 1;
    }

int main(void)
    {

    DIO_voidInit();

    TIMER0_VoidINIT();

    TIMER0_CallbackSetup(led);

    DIO_u8WritePortVal(DIO_u8PORT0, 0);

    Enable_Global_INT();

    TIMER0_Void_Delay_US(120);

    while (1)
	{
	if (flag1 == 1)
	    {
	    TIMER0_Void_Delay_US(120);
	    flag1 = 0;
	    }
	}

    return 0;

    }

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

void led(void)
    {

    flag = ~flag;

    DIO_u8WritePortVal(DIO_u8PORT0, flag);

    TIMER0_Void_Delay_MS(1000);

    }

int main(void)
    {

    DIO_voidInit();

    TIMER0_VoidINIT();

    TIMER0_CallbackSetup(led);

    DIO_u8WritePortVal(DIO_u8PORT0, 0);

    TIMER0_Void_Delay_MS(1000);

    Enable_Global_INT();

    while (1)
	{
//    DIO_u8WritePortVal(DIO_u8PORT0, 0xff);

	}

    return 0;

    }

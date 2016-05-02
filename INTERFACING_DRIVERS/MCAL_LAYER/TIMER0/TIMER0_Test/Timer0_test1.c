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
#include"../../DIO_DRIVER/DIO_private.h"

u8 flag = 0;

u8 flag1 = 0;

void led(void)
    {
    flag = ~flag;
//
    DIO_u8WritePortVal(DIO_u8PORT0, flag);
////*DIO_u8PORTA=0xff;
//
flag1 = 1;
    }

int main(void)
    {

    DIO_voidInit();

    TIMER0_VoidINIT();

    TIMER0_CallbackSetup(led);



    Enable_Global_INT();

//    *DIO_u8PORTA=0xff;

    TIMER0_Void_Delay_MS(90);


    while (1)
	{

//	    *DIO_u8PORTA=0xff;

	if (flag1 == 1)
	    {
//	    DIO_u8WritePortVal(DIO_u8PORT0, flag);
	    flag1 = 0;
	    TIMER0_Void_Delay_MS(500);

	    }

	}

    return 0;

    }

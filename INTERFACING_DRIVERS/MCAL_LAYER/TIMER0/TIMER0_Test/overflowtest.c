/*
 * overflowtest.c
 *
 *  Created on: Apr 4, 2016
 *      Author: Ahmed
 */
#include"../../../APPLICATION_LAYER/types.h"
#include"../TIMER0_interface.h"
#include "../../DIO_DRIVER/DIO_interface.h"

void main()
    {

    u8 Test_Flag = 1;

    u8 previous_sec = 0;

    u8 Current_sec = 0;

    DIO_voidInit();

    TIMER0_voidINIT();

    while (1)
	{

	Current_sec = TIMER0_u16readMS();

	if ((Current_sec != previous_sec))
	    {

	    Test_Flag = !Test_Flag;

	    }

	DIO_u8WritePinVal(DIO_u8PIN0, Test_Flag);

	previous_sec = Current_sec;

	}

    return;
    }

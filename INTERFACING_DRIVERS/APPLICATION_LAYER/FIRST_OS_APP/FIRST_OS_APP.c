/*
 * FIRST_OS_APP.c
 *
 *  Created on: Apr 20, 2016
 *      Author: Ahmed
 */

#include"../../Shared_Libraries/types.h"
#include"../../RTOS/RTOS_interface.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"

void TASK1(void);
void TASK2(void);
void TASK3(void);

void main()
    {

    u8 delay[3] =
	{
	0, 1, 3
	};

    RTOS_voidCreateTask(TASK1, 1);
    RTOS_voidCreateTask(TASK2, 2);
    RTOS_voidCreateTask(TASK3, 4);

    DIO_voidInit();
    RTOS_voidInit();

    RTOS_voidStart(delay);

    return;
    }

void TASK1(void)
    {
    static u8 APP_u8Toggle1 = 0;

    APP_u8Toggle1 = !APP_u8Toggle1;

    DIO_u8WritePinVal(DIO_u8PIN0, APP_u8Toggle1);

    return;
    }

void TASK2(void)
    {
    static u8 APP_u8Toggele2 = 0;

    APP_u8Toggele2 = !APP_u8Toggele2;

    DIO_u8WritePinVal(DIO_u8PIN1, APP_u8Toggele2);

    return;
    }

void TASK3(void)
    {
    static u8 APP_u8Toggle3 = 0;

    APP_u8Toggle3 = !APP_u8Toggle3;

    DIO_u8WritePinVal(DIO_u8PIN2, APP_u8Toggle3);

    return;
    }

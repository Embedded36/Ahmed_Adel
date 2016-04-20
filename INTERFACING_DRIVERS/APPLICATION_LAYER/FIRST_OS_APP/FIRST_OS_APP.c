/*
 * FIRST_OS_APP.c
 *
 *  Created on: Apr 20, 2016
 *      Author: Ahmed
 */

#include"../../Shared_Libraries/types.h"
#include"../../HAL_LAYER/RTOS/RTOS_interface.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"

void TASK1(void);
void TASK2(void);
void TASK3(void);


void main()
    {

    struct TCB TCB_ARRay[3];

    TCB_ARRay[0].ptr = TASK1;
    TCB_ARRay[0].count = 5;
    TCB_ARRay[1].ptr = TASK2;
    TCB_ARRay[1].count = 10;
    TCB_ARRay[2].ptr = TASK3;
    TCB_ARRay[2].count = 20;

    DIO_voidInit();
    RTOS_voidInit();
    RTOS_voidStart(TCB_ARRay);

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

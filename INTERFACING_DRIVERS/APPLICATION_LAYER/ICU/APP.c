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
void TASK4(void);

static u8 task2_done = 0;
static u8 lowcounter = 0;
static u8 high_counter = 0;

void main()
    {

    u8 delay[4] =
	{
	0, 0, 0, 1
	};

    RTOS_voidCreateTask(TASK1, 50);
    RTOS_voidCreateTask(TASK2, 1);
    RTOS_voidCreateTask(TASK3, 1);
    RTOS_voidCreateTask(TASK4, 4);

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
    static u8 APP_u8Flag = 0;

    u8 APP_u8Start_Counting;

    static u8 stop_flag = 0;

    if (!stop_flag)
	{
	DIO_u8ReadPinVal(DIO_u8PIN1, &APP_u8Start_Counting);

	if (APP_u8Start_Counting == DIO_u8HIGH)
	    {

	    APP_u8Flag = 1;

	    }
	else
	    {

	    APP_u8Flag = 0;

	    }

	}
    else
	{
	}

    if (APP_u8Flag)
	{
	high_counter++;
	}
    else
	{
	task2_done = 1;
	APP_u8Flag = 0;
	stop_flag = 1;
	}

    return;
    }

void TASK3(void)
    {

    static u8 APP_u8Start_Counting = 1;

    u8 temp;


    if (task2_done && APP_u8Start_Counting)
	{

	DIO_u8ReadPinVal(DIO_u8PIN1, &temp);

	if (temp == DIO_u8HIGH)
	    {

	    APP_u8Start_Counting = 0;

	    }
	else
	    {

	    lowcounter++;

	    }

	}
    else
	{
	}


    return;
    }

void TASK4(void)
    {

    DIO_u8WritePortVal(DIO_u8PORT1, high_counter);
    DIO_u8WritePortVal(DIO_u8PORT2, high_counter + lowcounter);

    return;
    }

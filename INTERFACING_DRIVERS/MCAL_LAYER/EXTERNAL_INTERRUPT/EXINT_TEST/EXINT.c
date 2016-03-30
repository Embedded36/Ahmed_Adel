/*
 * EXINT.c
 *
 *  Created on: Mar 29, 2016
 *      Author: Ahmed
 */
#include "../../../APPLICATION_LAYER/types.h"
#include"../EXINT_interface.h"
#include "../../DIO_DRIVER/DIO_interface.h"

void APP_voidLED2Toggle(void);
void APP_voidLED1Toggle(void);
void APP_voidLED3Toggle(void);


u8 Flag1 = 0;
u8 Flag2 = 0;
u8 Flag3 = 0;

void APP_voidLED1Toggle(void)
    {
    Flag1 = !Flag1;

    EXINT_ISR0CallBackSet(APP_voidLED2Toggle);

    return;
    }

void APP_voidLED2Toggle(void)
    {
    Flag2 = !Flag2;

    EXINT_ISR0CallBackSet(APP_voidLED3Toggle);

    return;
    }

void APP_voidLED3Toggle(void)
    {
    Flag3 = !Flag3;

    EXINT_ISR0CallBackSet(APP_voidLED1Toggle);

    return;
    }
int main()
    {

    DIO_voidInit();
    EXINT_voidInit();
    DIO_u8WritePortDir(DIO_u8PORT0, 0xff);
    EXINT_ISR0CallBackSet(APP_voidLED1Toggle);

    while (1)
	{
	if (Flag1 == 0)
	    {
	    DIO_u8WritePinVal(DIO_u8PIN0, DIO_u8HIGH);

	    }
	else
	    {
	    DIO_u8WritePinVal(DIO_u8PIN0, DIO_u8LOW);

	    }

	if (Flag2 == 0)
	    {
	    DIO_u8WritePinVal(DIO_u8PIN1, DIO_u8HIGH);

	    }
	else
	    {
	    DIO_u8WritePinVal(DIO_u8PIN1, DIO_u8LOW);

	    }

	if (Flag3 == 0)
	    {
	    DIO_u8WritePinVal(DIO_u8PIN2, DIO_u8HIGH);

	    }
	else
	    {
	    DIO_u8WritePinVal(DIO_u8PIN2, DIO_u8LOW);

	    }
	}
    return 0;
    }


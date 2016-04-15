/*
 * ADC_TEST.c
 *
 *  Created on: Mar 11, 2016
 *      Author: Ahmed
 */
#include"../../../Shared_Libraries/types.h"
#include"../USART_interface.h"
#include"../../DIO_DRIVER/DIO_interface.h"
#include "../../../Shared_Libraries/interrupt.h"

u16 test;
void callback(void)
    {

    test=USART_VoidReadRxBuffer();
    USART_voidTransmit(test);
    DIO_u8WritePortVal(DIO_u8PORT0,0x55);

    return;
    }
int main()
    {

    DIO_voidInit();
    DIO_u8WritePortDir(DIO_u8PORT0,0xff);
    DIO_u8WritePortVal(DIO_u8PORT0,0x0f);
    USART_voidInit();

    USART_VoidUSARTRXCallBackSet(callback);

    Enable_Global_INT();

    while (1)
	{
//	USART_voidTransmit('M');
//	USART_voidTransmit('O');
//	USART_voidTransmit('H');
//	USART_voidTransmit('A');
//	USART_voidTransmit('M');
//	USART_voidTransmit('E');
//	USART_voidTransmit('D');
//	USART_voidTransmit('\n');
	}

    return 0;

    }


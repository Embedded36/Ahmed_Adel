/*
 * ADC_TEST.c
 *
 *  Created on: Mar 11, 2016
 *      Author: Ahmed
 */
#include"../../../Shared_Libraries/types.h"
#include"../USART_interface.h"
#include"../../DIO_DRIVER/DIO_interface.h"

int main()
    {

    DIO_voidInit();
    USART_voidInit();

    while (1)
	{
	USART_voidTransmit('M');
	USART_voidTransmit('O');
	USART_voidTransmit('H');
	USART_voidTransmit('A');
	USART_voidTransmit('M');
	USART_voidTransmit('E');
	USART_voidTransmit('D');
	USART_voidTransmit('\n');
	}

    return 0;

    }


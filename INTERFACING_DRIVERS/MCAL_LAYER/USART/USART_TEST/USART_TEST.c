/*
 * ADC_TEST.c
 *
 *  Created on: Mar 11, 2016
 *      Author: Ahmed
 */
#include"../../../APPLICATION_LAYER/types.h"
#include"../USART_interface.h"
#include"../../DIO_DRIVER/DIO_interface.h"

int main()
    {

   USART_voidInit();

   while(1)
       {
       USART_voidTransmit('c');
      // break;
       }

    return 0;

    }


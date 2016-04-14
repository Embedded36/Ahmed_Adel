#include"../../Shared_Libraries/types.h"
#include"../../Shared_Libraries/util.h"
#include"USART_interface.h"
#include"USART_config.h"
#include"USART_private.h"

void USART_voidInit(void)
    {

    /*Comment!: Set Baud Rate*/
    *USART_u8UBRRH = (u8) (USART_u8BAUD >> 8);

    *USART_u8UBRRL = (u8) (USART_u8BAUD);

    /*Comment!: Enable receiver and transmitter*/
    SET_BIT(*USART_u8UCSRB, USART_u8TXEN);

    SET_BIT(*USART_u8UCSRB, USART_u8RXEN);

    /*Comment!: Choose other parameters*/
    *USART_u8UCSRC=CONC(1,0,USART_u8UPM1,USART_u8UPM0,USART_u8USBS,USART_u8UCSZ1,USART_u8UCSZ0,0);

    return;
    }

void USART_voidTransmit(u8 Copy_u8Data)
    {

    /* Wait for empty transmit buffer */
    while (!((*USART_u8UCSRA) & USART_u8TxFlagMask ))
	;
    /* Put data into buffer, sends the data */
    *USART_u8UDR = Copy_u8Data;

    return;
    }

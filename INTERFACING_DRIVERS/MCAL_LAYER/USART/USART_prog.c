#include"../../APPLICATION_LAYER/types.h"
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

    /*Comment!: Set frame format: bits per data*/
#if USART_u8NUM_BITS_PER_DATA==8

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    SET_BIT(*USART_u8UCSRC, USART_u8UCSZ0);
    SET_BIT(*USART_u8UCSRC, USART_u8UCSZ1);
    CLR_BIT(*USART_u8UCSRB, USART_u8UCSZ2);

#elif USART_u8NUM_BITS_PER_DATA==7

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    CLR_BIT(*USART_u8UCSRC, USART_u8UCSZ0);
    SET_BIT(*USART_u8UCSRC, USART_u8UCSZ1);
    CLR_BIT(*USART_u8UCSRB, USART_u8UCSZ2);

#elif USART_u8NUM_BITS_PER_DATA==6

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    SET_BIT(*USART_u8UCSRC, USART_u8UCSZ0);
    CLR_BIT(*USART_u8UCSRC, USART_u8UCSZ1);
    CLR_BIT(*USART_u8UCSRB, USART_u8UCSZ2);

#elif USART_u8NUM_BITS_PER_DATA==5

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    CLR_BIT(*USART_u8UCSRC, USART_u8UCSZ0);
    CLR_BIT(*USART_u8UCSRC, USART_u8UCSZ1);
    CLR_BIT(*USART_u8UCSRB, USART_u8UCSZ2);

#else
#error "USART_NUM_BITS_PER_DATA is out of range "
#endif

    /*Comment!: Set frame format: Number of stop bits*/
#if USART_u8NUM_STOP_BITS==1

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    CLR_BIT(*USART_u8UCSRC, USART_u8USBS);

#elif USART_u8NUM_STOP_BITS==2

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    SET_BIT(*USART_u8UCSRC, USART_u8USBS);

#else
#error "error at choosing stop bits"
#endif

    /*Comment!: Set frame format: Number of parity bits*/
#if USART_u8NUM_STOP_BITS==1

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    CLR_BIT(*USART_u8UCSRC, USART_u8USBS);

#elif USART_u8NUM_STOP_BITS==2

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    SET_BIT(*USART_u8UCSRC, USART_u8USBS);

#else
#error "error at choosing stop bits"
#endif

#if USART_u8NUM_PARITY==USART_u8NOPARITY

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    CLR_BIT(*USART_u8UCSRC, USART_u8UPM0);
    CLR_BIT(*USART_u8UCSRC, USART_u8UPM1);

#elif  USART_u8NUM_PARITY==USART_u8ODDPARITY

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    SET_BIT(*USART_u8UCSRC, USART_u8UPM0);
    SET_BIT(*USART_u8UCSRC, USART_u8UPM1);

#elif  USART_u8NUM_PARITY==USART_u8EVENPARITY

    SET_BIT(*USART_u8UCSRC, USART_u8URSEL);
    CLR_BIT(*USART_u8UCSRC, USART_u8UPM0);
    SET_BIT(*USART_u8UCSRC, USART_u8UPM1);

#else
#error "error at choosing parity"

#endif

    return;
    }

void USART_voidTransmit(u8 Copy_u8Data)
    {

    /* Wait for empty transmit buffer */
    while (!((*USART_u8UCSRA) & (1 << 5)))
	;
    /* Put data into buffer, sends the data */
    *USART_u8UDR = Copy_u8Data;

    return;
    }

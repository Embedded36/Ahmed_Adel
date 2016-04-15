#include"../../Shared_Libraries/types.h"
#include"../../Shared_Libraries/util.h"
#include"../../Shared_Libraries/System_Clock.h"
#include "../../Shared_Libraries/interrupt.h"
#include "../DIO_DRIVER/DIO_interface.h"
#include"USART_interface.h"
#include"USART_config.h"
#include"USART_private.h"
#include <avr/interrupt.h>/////////////////

/*Comment!: Pointer to call back function*/
static void (*USART_PvoidUSARTRXISR)(void);

/*Comment!: Software Buffer for Received data*/
static u16 USART_u16RxBuffer;

extern void USART_voidInit(void)
    {

    /*Comment!: Set Baud Rate*/
    *USART_u8UBRRH = (u8) (USART_u8BAUD >> 8);

    *USART_u8UBRRL = (u8) (USART_u8BAUD);

    /*Comment!: Choose other parameters*/
    *USART_u8UCSRC = CONC(1, 0, USART_u8UPM1, USART_u8UPM0, USART_u8USBS, USART_u8UCSZ1, USART_u8UCSZ0, 0);

    /*Comment!: Enable Receiving interrupt*/
    SET_BIT(*USART_u8UCSRB, USART_u8RXCIE);

    /*Comment!: Enable receiver and transmitter*/
    SET_BIT(*USART_u8UCSRB, USART_u8TXEN);

    SET_BIT(*USART_u8UCSRB, USART_u8RXEN);

    /*Comment!: Initialize call back function's pointer*/
    USART_PvoidUSARTRXISR = NULL;

    /*Comment!: Initialize Rx buffer*/
    USART_u16RxBuffer = 0;

    return;
    }

extern void USART_voidTransmit(u16 Copy_u8Data)
    {

#if USART_u8NUM_BITS_PER_DATA==9

    u8 Local_u8Temp;

    /*Comment!: Read bit 9 at data  */
    Local_u8Temp = GET_BIT(Copy_u8Data,9);

    /*Comment!: Load the ninth bit in serial buffer register */
    WRITE_BIT(*USART_u8UCSRB,USART_u8TXB8,Local_u8Temp);

#endif

    /*Comment!:  Wait for empty transmit buffer */
    while (!((*USART_u8UCSRA) & USART_u8TxFlagMask))
	;
    /*Comment!:  Put data into buffer, sends the data */
    *USART_u8UDR = (u8) Copy_u8Data;

    return;
    }

extern void USART_voidEnableTx(void)
    {

    SET_BIT(*USART_u8UCSRB, USART_u8TXEN);

    return;
    }

extern void USART_voidDisableTx(void)
    {

    CLR_BIT(*USART_u8UCSRB, USART_u8TXEN);

    return;
    }

extern void USART_voidEnableRx(void)
    {

    SET_BIT(*USART_u8UCSRB, USART_u8RXEN);

    return;
    }

extern void USART_voidDisableRx(void)
    {

    CLR_BIT(*USART_u8UCSRB, USART_u8RXEN);

    return;
    }

ISR(USART_RXC_vect)
//ISR(__vector_13)
    {

#if USART_u8NUM_BITS_PER_DATA==8

    USART_u16RxBuffer = *USART_u8UDR;

#elif USART_u8NUM_BITS_PER_DATA==9

    /*Comment!: Clear buffer*/
    USART_u16RxBuffer=0;

    /*Comment!: Load the ninth bit in serial buffer register */
    WRITE_BIT(USART_u16RxBuffer,8,GET_BIT(*USART_u8UCSRB,USART_u8TXB8));

    /*Comment!: Load the first byte in serial buffer register */
    USART_u16RxBuffer |=*USART_u8UDR;

#endif

    if (USART_PvoidUSARTRXISR)
	{

	USART_PvoidUSARTRXISR();

	}

    else

	{

	}

    }

extern void USART_VoidUSARTRXCallBackSet(void (*Copy_PvoidUSARTRXISR)(void))
    {

    USART_PvoidUSARTRXISR = Copy_PvoidUSARTRXISR;

    return;
    }

extern u16 USART_VoidReadRxBuffer(void)
    {

    /*Comment!:  Read Rx buffer*/
    return USART_u16RxBuffer;

    }

#ifndef _USART_PRIVATE_H_ 
#define _USART_PRIVATE_H_   

/*******************************************************/
/**************** Private Definitions ******************/
/*******************************************************/

/*Comment!: */
#if (((F_CPU)/(16*(USART_u8BAUDRATE)))-1)<4096
#define USART_u8BAUD    (((F_CPU)/(16*(USART_u8BAUDRATE)))-1)
#else
#error "Baud rate is out of range"
#endif

#define USART_u8RXEN    4
#define USART_u8TXEN    3
#define USART_u8URSEL   7
#define USART_u8TXB8    0
#define USART_u8RXCIE   7

#define USART_u8NOPARITY   0
#define USART_u8ODDPARITY  1
#define USART_u8EVENPARITY 2

#define USART_u8TxFlagMask (1 << 5)

#if USART_u8NUM_BITS_PER_DATA==9

#define USART_u8UCSZ0   1
#define USART_u8UCSZ1   1
#define USART_u8UCSZ2   1

#elif USART_u8NUM_BITS_PER_DATA==8

#define USART_u8UCSZ0   1
#define USART_u8UCSZ1   1
#define USART_u8UCSZ2   0

#elif USART_u8NUM_BITS_PER_DATA==7

#define USART_u8UCSZ0   0
#define USART_u8UCSZ1   1
#define USART_u8UCSZ2   0

#elif USART_u8NUM_BITS_PER_DATA==6

#define USART_u8UCSZ0   1
#define USART_u8UCSZ1   0
#define USART_u8UCSZ2   0

#elif USART_u8NUM_BITS_PER_DATA==5

#define USART_u8UCSZ0   0
#define USART_u8UCSZ1   0
#define USART_u8UCSZ2   0

#else
#error "USART_NUM_BITS_PER_DATA is out of range "
#endif

#if USART_u8NUM_STOP_BITS==1

#define USART_u8USBS      0

#elif USART_u8NUM_STOP_BITS==2

#define USART_u8USBS      1

#else
#error "error at choosing stop bits"
#endif

#if USART_u8NUM_PARITY==USART_u8NOPARITY

#define USART_u8UPM0    0
#define USART_u8UPM1    0

#elif  USART_u8NUM_PARITY==USART_u8ODDPARITY

#define USART_u8UPM0    1
#define USART_u8UPM1    1

#elif  USART_u8NUM_PARITY==USART_u8EVENPARITY

#define USART_u8UPM0    0
#define USART_u8UPM1    1

#else
#error "error at choosing parity"

#endif

/*******************************************************/
/***************** Register Addresses ******************/
/*******************************************************/
#define USART_u8UBRRL  ((volatile u8*)(0x29))
#define USART_u8UBRRH  ((volatile u8*)(0x40))
#define USART_u8UCSRB  ((volatile u8*)(0x2A))
#define USART_u8UCSRC  ((volatile u8*)(0x40))
#define USART_u8UCSRA  ((volatile u8*)(0x2B))
#define USART_u8UDR    ((volatile u8*)(0x2C))

#endif  

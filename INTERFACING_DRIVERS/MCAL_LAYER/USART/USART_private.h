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
#define USART_u8UCSZ0   1
#define USART_u8UCSZ1   2
#define USART_u8UCSZ2   2
#define USART_u8USBS    3
#define USART_u8UPM0    4
#define USART_u8UPM1    5

#define USART_u8NOPARITY 0
#define USART_u8ODDPARITY 1
#define USART_u8EVENPARITY 2
/*******************************************************/
/***************** Register Addresses ******************/
/*******************************************************/
#define USART_u8UBRRL  ((volatile u8*)(0x29))
#define USART_u8UBRRH  ((volatile u8*)(0x40))
#define USART_u8UCSRB  ((volatile u8*)(0x2A))
#define USART_u8UCSRC  ((volatile u8*)(0x40))
#define USART_u8UCSRA  ((volatile u8*)(0x2B))
#define USART_u8UDR    ((volatile u8*)(0x2C))

/*******************************************************/  
/*****************  Private Functions  *****************/  
/*******************************************************/  
  
#define CLR_BIT(Reg,Bit_no)                   ((Reg)&=(~(1<<(Bit_no))))
#define SET_BIT(Reg,Bit_no)                   ((Reg)|=(1<<(Bit_no)))

#endif  

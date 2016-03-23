#ifndef _USART_CONFIG_H_ 
#define _USART_CONFIG_H_ 
  
  
/*******************************************************/  
/**************** Public Definitions *******************/  
/*******************************************************/  
  
/*Comment!: Baud Rate (number of bits per second)*/
/*Range!  : */ 

#define USART_u8BAUDRATE     9600UL

/*Comment!: Baud Rate (number of bits per second)*/
/*Range!  : */
#define F_CPU                4000000UL


/*Comment!: Baud Rate (number of bits per second)*/
/*Range!  : */
#define USART_u8NUM_BITS_PER_DATA     8

/*Comment!: Baud Rate (number of bits per second)*/
/*Range!  : */
#define USART_u8NUM_STOP_BITS     1

/*Comment!: Baud Rate (number of bits per second)*/
/*Range!  :USART_u8NOPARITY-USART_u8EVENPARITY-USART_u8ODDPARITY */
#define USART_u8NUM_PARITY USART_u8NOPARITY

#endif 

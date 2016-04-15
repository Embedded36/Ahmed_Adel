#ifndef _USART_INTERFACE_H_ 
#define _USART_INTERFACE_H_   

/*******************************************************/
/***************** Public Definitions ******************/
/*******************************************************/

/*Comment!: */

/*******************************************************/
/*****************  Public Functions  ******************/
/*******************************************************/

/*Comment!:  Initialize Usart */
extern void USART_voidInit(void);

/*Comment!:  Transmit data*/
extern void USART_voidTransmit(u16 Copy_u8Data);

/*Comment!:  Enable Tx */
extern void USART_voidEnableTx(void);

/*Comment!:  Disable Tx*/
extern void USART_voidDisableTx(void);

/*Comment!:  Enable Rx*/
extern void USART_voidEnableRx(void);

/*Comment!:  Disable Rx*/
extern  void USART_voidDisableRx(void);

/*Comment!:  Set call back function*/
extern void USART_VoidUSARTRXCallBackSet(void (*Copy_PvoidUSARTRXISR)(void));

/*Comment!:  Read Rx buffer*/
extern u16 USART_VoidReadRxBuffer(void);


#endif  

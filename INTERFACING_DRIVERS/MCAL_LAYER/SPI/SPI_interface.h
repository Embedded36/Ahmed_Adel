#ifndef _SPI_INTERFACE_H_ 
#define _SPI_INTERFACE_H_   
  
  
/*******************************************************/  
/***************** Public Definitions ******************/  
/*******************************************************/  
  
/*Comment!:Slaves ID */
#define SPI_u8SLAVE1 0
#define SPI_u8SLAVE2 1
#define SPI_u8SLAVE3 2
#define SPI_u8SLAVE4 3
  
/*******************************************************/  
/*****************  Public Functions  ******************/  
/*******************************************************/  
  
/*Comment!: Initialization Function */
extern void SPI_voidInit(void);

/*Comment!: Enable SPI */
extern void SPI_voidEnable(void);

/*Comment!: Disable SPI */
extern void SPI_voidDisable(void);

/*Comment!: Send packet of bytes*/
/*Comment!: Copy_u8Transmittedpacket_Address is a pointer to the data that will be sent*/
/*Comment!: Copy_u8Receivedpacket_Address is a pointer to a memory location to store received data ,it is optional*/
/*Comment!: To disable this feature send NULL instead of sending a memory location */
extern u8 SPI_u8Send_Packet(u8* Copy_u8Transmittedpacket_Address, u8* Copy_u8Receivedpacket_Address,
	u8 Copy_u8Slave_Id, u8 Copy_u8packet_Size);

/*Comment!: Set pointer to call back function */
extern void SPI_ISRCallBackSet(void (*Copy_PvoidSPIISR)(void));

/*Comment!: Read received data */
extern u8 SPI_ReadReceivedData(void);

#endif  

#ifndef _SPI_PRIVATE_H_ 
#define _SPI_PRIVATE_H_   
  
  
/*******************************************************/  
/**************** Private Definitions ******************/  
/*******************************************************/  
  
/*Comment!: Communication Progress*/
#define SPI_u8TRANSMISSION_IN_PROGRESS 0

/*Comment!: Communication Modes*/
#define SPI_u8MASTER 1
#define SPI_u8SLAVE  0

/*Comment!: Communication Speeds*/
#define SPI_u8FOSC_DIVIDED_BY_2   0
#define SPI_u8FOSC_DIVIDED_BY_4   1
#define SPI_u8FOSC_DIVIDED_BY_8   2
#define SPI_u8FOSC_DIVIDED_BY_16  3
#define SPI_u8FOSC_DIVIDED_BY_32  4
#define SPI_u8FOSC_DIVIDED_BY_64  5
#define SPI_u8FOSC_DIVIDED_BY_128 6

/*Comment!: SPI PINS*/
#define SPI_u8MOSI  DIO_u8PIN13
#define SPI_u8MISO  DIO_u8PIN14
#define SPI_u8SCK   DIO_u8PIN15
#define SPI_u8SS    DIO_u8PIN12
#define SPI_u8SPE   6
#define SPI_u8SPR0  0
#define SPI_u8SPR1  1
#define SPI_u8SPI2X 0
#define SPI_u8SPIF  7
#define SPI_u8SPIE  7
#define SPI_u8MSTR 4
#define SPI_u8CPHA 2
#define SPI_u8CPOL 3
/*******************************************************/
/***************** Register Addresses ******************/
/*******************************************************/
#define SPI_u8SPDR   ((volatile u8*)(0x2F))
#define SPI_u8SPSR   ((volatile u8*)(0x2E))
#define SPI_u8SPCR   ((volatile u8*)(0x2D))

#endif

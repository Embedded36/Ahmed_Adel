#ifndef _SPI_CONFIG_H_ 
#define _SPI_CONFIG_H_ 
  
/*******************************************************/  
/**************** I/O pins directions ******************/
/*******************************************************/

/*Comment!: If SPI was configured as a master*/
/*Comment!: SPI_u8MOSI----> DIO_u8OUTPUT*/
/*Comment!: SPI_u8MISO----> DIO_u8INPUT*/
/*Comment!: SPI_u8SCK----> DIO_u8OUTPUT*/
/*Comment!: SPI_u8SS----> DIO_u8OUTPUT*/

/*Comment!: If SPI was configured as a master*/
/*Comment!: SPI_u8MOSI----> DIO_u8INPUT*/
/*Comment!: SPI_u8MISO----> DIO_u8OUTPUT*/
/*Comment!: SPI_u8SCK----> DIO_u8INPUT*/
/*Comment!: SPI_u8SS----> DIO_u8INPUT*/

/*******************************************************/
/**************** Public Definitions *******************/  
/*******************************************************/  

/*Comment!: Communication Mode*/
/*Range!  : SPI_u8MASTER -SPI_u8Slave*/
#define SPI_u8MODE  SPI_u8MASTER

/*Comment!: Communication Speed*/
/*Range!  : SPI_u8FOSC_DIVIDED_BY_2 ~ SPI_u8FOSC_DIVIDED_BY_128*/
#define SPI_u8SPEED SPI_u8FOSC_DIVIDED_BY_16

/*Comment!: Clock polarity*/
/*Range!  :0-1*/
/* SPI_u8CLOCKPOLARITY  Leading Edge   Trailing Edge */
/* 0                    Rising         Falling       */
/* 1                    Falling        Rising        */
#define SPI_u8CLOCKPOLARITY 0

/*Comment!: Clock phase*/
/*Comment!:The settings of the Clock Phase bit (CPHA) determine if data is sampled on the leading (first) or*/
/*Comment!:trailing (last) edge of SCK*/
/*Comment!:for more information back to page 144 at Avr data sheet*/
/*Range!  :0-1*/
#define SPI_u8CLOCKPHASE 0

/*Comment!: Number of Slaves*/
/*Range!  : 1 ~ 4*/
#define SPI_u8SLAVES_NUM  1

/*Comment!: Slaves Control Pins*/
/*Comment!: If Spi module was configured as a master these pins must be configured as DIO_u8OUTPUT */
/*Comment!: If Spi module was configured as a master these pins should be initialized as DIO_u8OLOW*/
/*Range!  : DIO_u8PIN0~DIO_u8PIN11 -DIO_u8PIN16~DIO_u8PIN31*/
#define SPI_u8SLAVE1_CONTROL_PIN DIO_u8PIN24
#define SPI_u8SLAVE2_CONTROL_PIN DIO_u8PIN1
#define SPI_u8SLAVE3_CONTROL_PIN DIO_u8PIN2
#define SPI_u8SLAVE4_CONTROL_PIN DIO_u8PIN3
  
#endif 

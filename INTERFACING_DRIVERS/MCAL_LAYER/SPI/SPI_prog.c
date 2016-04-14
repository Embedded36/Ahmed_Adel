#include"../../Shared_Libraries/types.h"
#include"../../Shared_Libraries/util.h"
#include "../../Shared_Libraries/interrupt.h"
#include "../DIO_DRIVER/DIO_interface.h"
#include"SPI_interface.h"  
#include"SPI_config.h" 
#include"SPI_private.h"

/*******************************************************/
/***************** Array Of slave Pins ****************/
/*******************************************************/

/*Comment!: static pointer to callback function */
static void (*SPI_PvoidSPIISR)(void);

#if SPI_u8MODE==SPI_u8MASTER

#if SPI_u8SLAVES_NUM==1

static volatile u8 SPI_SLAVE_PINS_ARRAY[SPI_u8SLAVES_NUM] =
    {
    SPI_u8SLAVE1_CONTROL_PIN
    };

#elif SPI_u8SLAVES_NUM==2

static volatile u8 SPI_SLAVE_PINS_ARRAY[SPI_u8SLAVES_NUM] =
    {SPI_u8SLAVE1_CONTROL_PIN ,SPI_u8SLAVE2_CONTROL_PIN};

#elif SPI_u8SLAVES_NUM==3

static volatile u8 SPI_SLAVE_PINS_ARRAY[SPI_u8SLAVES_NUM] =
    {SPI_u8SLAVE1_CONTROL_PIN ,SPI_u8SLAVE2_CONTROL_PIN , SPI_u8SLAVE3_CONTROL_PIN};

#elif SPI_u8SLAVES_NUM==4

static volatile u8 SPI_SLAVE_PINS_ARRAY[SPI_u8SLAVES_NUM] =
    {SPI_u8SLAVE1_CONTROL_PIN ,SPI_u8SLAVE2_CONTROL_PIN , SPI_u8SLAVE3_CONTROL_PIN ,SPI_u8SLAVE4_CONTROL_PIN};

#else

#error "number of slaves is out of range"

#endif

#endif

/******************************************************/
/******************** Functions************************/
/******************************************************/

extern void SPI_voidInit(void)
    {

    /*Comment!:initialize pointer to call back function*/
    SPI_PvoidSPIISR = NULL;

    /*Comment!:Check SPI mode */
#if SPI_u8MODE==SPI_u8MASTER

    /*Comment!: Set SPI as a master*/
    SET_BIT(*SPI_u8SPCR, SPI_u8MSTR);

    /*Comment!: Set direction of slave bits and make their output= DIO_u8HIGH*/
#if ((SPI_u8SLAVES_NUM > 4)||(SPI_u8SLAVES_NUM <1) )

#error "Number of spi slaves is out of range"

#endif

#elif SPI_u8MODE==SPI_u8SLAVE

    /*Comment!: Set SPI as a slave*/
    CLR_BIT(*SPI_u8SPCR, SPI_u8MSTR);

    /*Comment!: Enable SPI interrupt*/
    SET_BIT(*SPI_u8SPCR, SPI_u8SPIE);

#else

#error "SPI mode must be master or slave"

#endif

    /*Comment!: Setting SPI speed */
#if SPI_u8SPEED==SPI_u8FOSC_DIVIDED_BY_2

    CLR_BIT(*SPI_u8SPCR, SPI_u8SPR0);
    CLR_BIT(*SPI_u8SPCR, SPI_u8SPR1);
    SET_BIT(*SPI_u8SPSR, SPI_u8SPI2X);

#elif SPI_u8SPEED==SPI_u8FOSC_DIVIDED_BY_4

    CLR_BIT(*SPI_u8SPCR,SPI_u8SPR0);
    CLR_BIT(*SPI_u8SPCR,SPI_u8SPR1);
    CLR_BIT(*SPI_u8SPSR,SPI_u8SPI2X);

#elif SPI_u8SPEED==SPI_u8FOSC_DIVIDED_BY_8

    SET_BIT(*SPI_u8SPCR,SPI_u8SPR0);
    CLR_BIT(*SPI_u8SPCR,SPI_u8SPR1);
    SET_BIT(*SPI_u8SPSR,SPI_u8SPI2X);

#elif SPI_u8SPEED==SPI_u8FOSC_DIVIDED_BY_16

    SET_BIT(*SPI_u8SPCR, SPI_u8SPR0);
    CLR_BIT(*SPI_u8SPCR, SPI_u8SPR1);
    CLR_BIT(*SPI_u8SPSR, SPI_u8SPI2X);

#elif SPI_u8SPEED==SPI_u8FOSC_DIVIDED_BY_32

    CLR_BIT(*SPI_u8SPCR,SPI_u8SPR0);
    SET_BIT(*SPI_u8SPCR,SPI_u8SPR1);
    SET_BIT(*SPI_u8SPSR,SPI_u8SPI2X);

#elif SPI_u8SPEED==SPI_u8FOSC_DIVIDED_BY_64
    SET_BIT(*SPI_u8SPCR,SPI_u8SPR0);
    SET_BIT(*SPI_u8SPCR,SPI_u8SPR1);
    SET_BIT(*SPI_u8SPSR,SPI_u8SPI2X);

#elif SPI_u8SPEED==SPI_u8FOSC_DIVIDED_BY_128

    SET_BIT(*SPI_u8SPCR,SPI_u8SPR0);
    SET_BIT(*SPI_u8SPCR,SPI_u8SPR1);
    CLR_BIT(*SPI_u8SPSR,SPI_u8SPI2X);

#else

#error "SPI speed is out of range"

#endif

    /*Comment!: Set clock phase*/
#if SPI_u8CLOCKPHASE==0
    CLR_BIT(*SPI_u8SPCR, SPI_u8CPHA);

#elif SPI_u8CLOCKPHASE==1
    SET_BIT(*SPI_u8SPCR, SPI_u8CPHA);

#else
#error "clock phase value is wrong "
#endif

    /*Comment!: Set clock polarity*/
#if SPI_u8CLOCKPOLARITY==0
    CLR_BIT(*SPI_u8SPCR, SPI_u8CPOL);

#elif SPI_u8CLOCKPOLARITY==1
    SET_BIT(*SPI_u8SPCR, SPI_u8CPOL);

#else
#error "clock polarity value is wrong "
#endif

    /*Comment!: Enable SPI*/
    SPI_voidEnable();

    return;
    }

extern void SPI_voidEnable(void)
    {

    SET_BIT(*SPI_u8SPCR, SPI_u8SPE);

    return;
    }

extern void SPI_voidDisable(void)
    {

    CLR_BIT(*SPI_u8SPCR, SPI_u8SPE);

    return;
    }

extern u8 SPI_u8Send_Packet(u8* Copy_u8Transmittedpacket_Address, u8* Copy_u8Receivedpacket_Address,
	u8 Copy_u8Slave_Id, u8 Copy_u8packet_Size)

    {

    /*Comment!:Check SPI mode */
#if SPI_u8MODE == SPI_u8MASTER

    u8 Local_u8ErrorFlag;
    u8 Local_u8TransmissionFlag;
    u8 Local_u8SLAVE_CONTROL_PIN;
    u8 Local_u8LoopCounter;

    /*Comment!:Check Slave Id in range */
    if ((Copy_u8Slave_Id < SPI_u8SLAVES_NUM) && (Copy_u8Transmittedpacket_Address))
	{

	/*Comment!: Fetch Slave control pin number */
	Local_u8SLAVE_CONTROL_PIN = SPI_SLAVE_PINS_ARRAY[Copy_u8Slave_Id];

	/*Comment!: Enable Communication with this slave */
	DIO_u8WritePinVal(Local_u8SLAVE_CONTROL_PIN, DIO_u8LOW);

	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < Copy_u8packet_Size; Local_u8LoopCounter++)
	    {

	    /*Comment!: send byte */
	    *SPI_u8SPDR = *(Copy_u8Transmittedpacket_Address + Local_u8LoopCounter);

	    /* Comment!:Wait for transmission complete */
	    do
		{
		Local_u8TransmissionFlag = GET_BIT((*SPI_u8SPSR), SPI_u8SPIF);
		} while (Local_u8TransmissionFlag == SPI_u8TRANSMISSION_IN_PROGRESS);

	    /* Comment!:copying received data to the pointer sent by application  */
	    if (Copy_u8Receivedpacket_Address)
		{

		*(Copy_u8Receivedpacket_Address + Local_u8LoopCounter) = *SPI_u8SPDR;

		}
	    else
		{

		}

	    }

	/*Comment!: Disable Communication with this slave */
	DIO_u8WritePinVal(Local_u8SLAVE_CONTROL_PIN, DIO_u8HIGH);

	Local_u8ErrorFlag = ok;

	}
    else
	{
	Local_u8ErrorFlag = error;
	}

    return Local_u8ErrorFlag;

#elif  SPI_u8MODE == SPI_u8SLAVE

    u8 Local_u8ErrorFlag = error;

    return Local_u8ErrorFlag;

#else

#error "SPI mode must be master or slave"

#endif
    }

extern void SPI_ISRCallBackSet(void (*Copy_PvoidSPIISR)(void))
    {

    SPI_PvoidSPIISR = Copy_PvoidSPIISR;

    return;
    }

ISR(__vector_10)
    {

    /*Comment!: check that callback function is set*/
    if (SPI_PvoidSPIISR)
	{

	SPI_PvoidSPIISR();

	}

    else

	{

	}

    }

extern u8 SPI_ReadReceivedData(void)
    {

    /*Comment!: return data at spi tx/rx buffer */
    return (*SPI_u8SPDR);
    }

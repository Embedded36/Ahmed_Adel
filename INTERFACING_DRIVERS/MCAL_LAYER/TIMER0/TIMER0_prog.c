#include"../../APPLICATION_LAYER/types.h"
#include"../../Shared_Libraries/interrupt.h"
#include"TIMER0_interface.h"
#include"TIMER0_config.h"
#include"TIMER0_private.h"
#include "../DIO_DRIVER/DIO_interface.h"

static u16 TIMER0_u16Us = 0;
static u16 TIMER0_u16Ms = 0;
static u16 TIMER0_u16S = 0;

extern void TIMER0_voidINIT(void)
    {

    *TIMER0_u8TCNT0 = 0;

//overflow interrupt enable
    (*TIMER0_u8TIMSK) |= 0x01;

    __asm("SEI");

    //prescaler
    (*TIMER0_u8TCCR0) |= 0x03;

    return;
    }

extern u16 TIMER0_u16readMS(void)
    {
    return TIMER0_u16Ms;
    }

ISR(__vector_11)
    {

    __asm("CLI");

    TIMER0_u16Us += ((64 / 4) * 256);

    if (TIMER0_u16Us > 1000)
	{

	TIMER0_u16Ms += (TIMER0_u16Us / 1000);

	TIMER0_u16Us = (TIMER0_u16Us % 1000);

	}
    else
	{

	}

    if (TIMER0_u16Ms > 1000)
	{

	TIMER0_u16S += (TIMER0_u16Ms / 1000);

	TIMER0_u16Ms = (TIMER0_u16Ms % 1000);

	}
    else
	{

	}

    __asm("SEI");

    }

extern void TIMER0_voidReset(void)
    {

    *TIMER0_u8TCNT0 = 0;
    TIMER0_u16Us = 0;
    TIMER0_u16Ms = 0;
    TIMER0_u16S = 0;

    return;
    }

#include"../../APPLICATION_LAYER/types.h"
#include"../../Shared_Libraries/interrupt.h"
#include"TIMER0_interface.h"
#include"TIMER0_config.h"
#include"TIMER0_private.h"
#include "../DIO_DRIVER/DIO_interface.h"

static u32 counter=0;
void TIMER_voidINIT()
    {


    (*TIMER0_u8TCCR0)|=0b00000101;
    //(*TIMER_u8TCCR0)&=0b11111101;


    *TIMER0_u8TCNT0=0;

    (*TIMER0_u8TIMSK)|=0x01;

    __asm("SEI");

    return;
    }

extern u32 Timer0_u32read(void)
    {
    return counter;
    }
ISR(__vector_11)
    {

    __asm("CLI");

	DIO_u8WritePortVal(DIO_u8PORT2, 0xff);

    __asm("SEI");
    }

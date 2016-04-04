#include"../../APPLICATION_LAYER/types.h"
#include"TIMER_interface.h"  
#include"TIMER_config.h" 
#include"TIMER_private.h"
#include "../DIO_DRIVER/DIO_interface.h"

static u32 counter=0;
void TIMER_voidINIT()
    {


    (*TIMER_u8TCCR0)|=0b00000101;
    //(*TIMER_u8TCCR0)&=0b11111101;


    *TIMER_u8TCNT0=0;

    (*TIMER_u8TIMSK)|=0x01;

    __asm("SEI");

    return;
    }

extern u32 Timer_u32read(void)
    {
    return counter;
    }
ISR(__vector_11)
    {

    __asm("CLI");

	DIO_u8WritePortVal(DIO_u8PORT2, 0xff);

    __asm("SEI");
    }

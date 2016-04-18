#include"../../Shared_Libraries/types.h"
#include"../../Shared_Libraries/System_Clock.h"
//#include"../../Shared_Libraries/interrupt.h"
#include "../DIO_DRIVER/DIO_interface.h"
#include"TIMER0_interface.h"
#include"TIMER0_config.h"
#include"TIMER0_private.h"
#include<avr/interrupt.h>

static u32 Timer0_u32MaxOverFlow;
static u32 Timer0_u32NumOverFlow;
static u32 Timer0_u32MaxCompTicks;

static void (*Timer0_PvoidTimer0ISR)(void);

extern void TIMER0_VoidINIT(void)
    {

    return;
    }

extern void TIMER0_Void_Delay_US(u32 Copy_u32Us)
    {

    u32 Local_u32NumTicks;

    Local_u32NumTicks = Copy_u32Us * (F_CPU / 1000000);

    Timer0_u32MaxOverFlow = Local_u32NumTicks / 256;

    Timer0_u32MaxCompTicks=200;// = Local_u32NumTicks % 256;

    if (Timer0_u32MaxOverFlow)
	{

	*TIMER0_u8TCNT0 = 0;

	//overflow interrupt enable
	(*TIMER0_u8TIMSK) |= 0x01;

	Timer0_u32NumOverFlow = 0;

	//No prescaler
	(*TIMER0_u8TCCR0) |= 0x01;

	}

    else
	{

	*TIMER0_u8OCR0 = Timer0_u32MaxCompTicks;

//	//ctc mode
	(*TIMER0_u8TCCR0) |= 0x08;
//	//deactivate ctc mode
//	    (*TIMER0_u8TCCR0) &= 0xf7;
//	//overflow interrupt disable
//	(*TIMER0_u8TIMSK) &= ~0x01;
//
	//reset counter
	*TIMER0_u8TCNT0 = 0;
	//	//No prescaler
	(*TIMER0_u8TCCR0) |= 0x01;

	//CTC interrupt Enable
	(*TIMER0_u8TIMSK) |= 0x02;

	}

    return;

    }

extern void TIMER0_Void_Delay_MS(u32 Copy_u32Ms)
    {

    u32 Local_u32NumTicks;

    Local_u32NumTicks = Copy_u32Ms * (F_CPU / 1000);

    Timer0_u32MaxOverFlow = Local_u32NumTicks / 256;

    Timer0_u32MaxCompTicks = Local_u32NumTicks % 256;

    if (Timer0_u32MaxOverFlow)
	{

	*TIMER0_u8TCNT0 = 0;

	//overflow interrupt enable
	(*TIMER0_u8TIMSK) |= 0x01;

	Timer0_u32NumOverFlow = 0;

	//No prescaler
	(*TIMER0_u8TCCR0) |= 0x01;

	}

    else
	{

	//ctc mode
	(*TIMER0_u8TCCR0) |= 0x08;

	*TIMER0_u8OCR0 = Timer0_u32MaxCompTicks;

	//overflow interrupt disable
	(*TIMER0_u8TIMSK) &= ~0x01;

	//CTC interrupt Enable
	(*TIMER0_u8TIMSK) |= 0x02;

	}

    return;
    }

//ISR (__vector_11)
ISR(TIMER0_OVF_vect)
    {

    Timer0_u32NumOverFlow++;

    if (Timer0_u32NumOverFlow == Timer0_u32MaxOverFlow)

	{

//	//disable timer
//	(*TIMER0_u8TCCR0) &= 0b11111000;
//
//	//overflow interrupt disable
//	(*TIMER0_u8TIMSK) &= ~0x01;
//
//	Timer0_PvoidTimer0ISR();

        //ctc mode
	(*TIMER0_u8TCCR0) |= 0x08;

	*TIMER0_u8OCR0 = 200;

	//overflow interrupt disable
	(*TIMER0_u8TIMSK) &= ~0x01;

	//CTC interrupt Enable
	(*TIMER0_u8TIMSK) |= 0x02;
	//    Timer0_PvoidTimer0ISR();

	}

    else
	{

	}

    }

ISR(TIMER0_COMP_vect)
    {

    //deactivate ctc mode
    // (*TIMER0_u8TCCR0) &= 0xf7;

    //compare interrupt disable
    (*TIMER0_u8TIMSK) &= ~0x02;
//disable timer
    (*TIMER0_u8TCCR0) &= 0b11111110;

    Timer0_PvoidTimer0ISR();

//	(*TIMER0_u8TCCR0) |= 0x01;

    }

extern void TIMER0_CallbackSetup(void (*Copy_PvoidTimer0ISR)(void))
    {

    Timer0_PvoidTimer0ISR = Copy_PvoidTimer0ISR;

    return;
    }

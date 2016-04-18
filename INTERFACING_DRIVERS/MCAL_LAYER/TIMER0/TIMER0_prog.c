#include"../../Shared_Libraries/types.h"
#include"../../Shared_Libraries/System_Clock.h"
#include"../../Shared_Libraries/interrupt.h"
#include"TIMER0_interface.h"
#include"TIMER0_config.h"
#include"TIMER0_private.h"

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

     Timer0_u32MaxCompTicks = Local_u32NumTicks % 256;

     if (Timer0_u32MaxOverFlow)
 	{
 	//reset timer
 	*TIMER0_u8TCNT0 = 0;

 	//overflow interrupt enable
 	(*TIMER0_u8TIMSK) |= 0x01;

 	Timer0_u32NumOverFlow = 0;

 	//No prescaler
 	(*TIMER0_u8TCCR0) |= 0x01;
 	}
     else
 	{
 	//activate compare match

	 //CTC interrupt Enable
	 	(*TIMER0_u8TIMSK) |= 0x02;

	 	//ctc mode
	 	(*TIMER0_u8TCCR0) |= 0x08;

	 	//set value at compare match register
	 	*TIMER0_u8OCR0 = Timer0_u32MaxCompTicks;

 		//No prescaler
 			(*TIMER0_u8TCCR0) |= 0x01;

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
	//reset timer
	*TIMER0_u8TCNT0 = 0;

	//overflow interrupt enable
	(*TIMER0_u8TIMSK) |= 0x01;

	Timer0_u32NumOverFlow = 0;

	//No prescaler
	(*TIMER0_u8TCCR0) |= 0x01;
	}
    else
	{
	//activate compare match

	//CTC interrupt Enable
		(*TIMER0_u8TIMSK) |= 0x02;

		//ctc mode
		(*TIMER0_u8TCCR0) |= 0x08;

		//set value at compare match register
		*TIMER0_u8OCR0 = Timer0_u32MaxCompTicks;
		//No prescaler
			(*TIMER0_u8TCCR0) |= 0x01;

	}

    return;
    }

ISR (__vector_11)
    {

    Timer0_u32NumOverFlow++;

    if (Timer0_u32NumOverFlow == Timer0_u32MaxOverFlow)

	{

	//disable timer
	//(*TIMER0_u8TCCR0) &= 0b11111000;

	//overflow interrupt disable
	(*TIMER0_u8TIMSK) &= ~0x01;

	//Timer0_PvoidTimer0ISR();

	//CTC interrupt Enable
	(*TIMER0_u8TIMSK) |= 0x02;

	//ctc mode
	(*TIMER0_u8TCCR0) |= 0x08;

	//set value at compare match register
	*TIMER0_u8OCR0 = Timer0_u32MaxCompTicks;

	}

    else
	{

	}

    }

ISR (__vector_10)
    {

    //disable timer
    (*TIMER0_u8TCCR0) &= 0b11111000;

    Timer0_PvoidTimer0ISR();

    //CTC interrupt disable
    (*TIMER0_u8TIMSK) &= ~0x02;

    //ctc mode
    (*TIMER0_u8TCCR0) &= ~0x08;

    }

extern void TIMER0_CallbackSetup(void (*Copy_PvoidTimer0ISR)(void))
    {

    Timer0_PvoidTimer0ISR = Copy_PvoidTimer0ISR;

    return;
    }

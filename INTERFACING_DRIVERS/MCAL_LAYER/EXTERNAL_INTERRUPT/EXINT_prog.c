#include"../../Shared_Libraries/types.h"
#include "../../Shared_Libraries/interrupt.h"
#include"EXINT_interface.h"  
#include"EXINT_config.h" 
#include"EXINT_private.h"

static void (*EXINT_PvoidEXINT0ISR)(void);
static void (*EXINT_PvoidEXINT1ISR)(void);
static void (*EXINT_PvoidEXINT2ISR)(void);

extern void EXINT_voidInit(void)
    {

    EXINT_PvoidEXINT0ISR = 0;

    EXINT_PvoidEXINT0ISR = 0;

    EXINT_PvoidEXINT0ISR = 0;

    EXINT_voidSetMode(EXINT_u8INT0, EXINT_u8EXINT0MODE);

    EXINT_voidSetMode(EXINT_u8INT1, EXINT_u8EXINT1MODE);

    EXINT_voidSetMode(EXINT_u8INT2, EXINT_u8EXINT2MODE);

#if EXINT_u8EXINT0STATE==EXINT_u8ENABLED
    EXINT_ENABLEINT(EXINT_u8INT0);

#elif EXINT_u8EXINT0STATE==EXINT_u8DISABLED
    EXINT_DISABLEINT(EXINT_u8INT0);

#else
#error "INT0 Isn't enabled or disabled"
#endif

#if EXINT_u8EXINT1STATE==EXINT_u8ENABLED
    EXINT_ENABLEINT(EXINT_u8INT1);

#elif EXINT_u8EXINT1STATE==EXINT_u8DISABLED
    EXINT_DISABLEINT(EXINT_u8INT1);

#else
#error "INT1 Isn't enabled or disabled"
#endif

#if EXINT_u8EXINT3STATE==EXINT_u8ENABLED
    EXINT_ENABLEINT(EXINT_u8INT3);

#elif EXINT_u8EXINT2STATE==EXINT_u8DISABLED
    EXINT_DISABLEINT(EXINT_u8INT2);

#else
#error "INT3 Isn't enabled or disabled"
#endif

    return;
    }

extern u8 EXINT_voidSetMode(u8 Copy_u8IntId, u8 Copy_u8IntMode)
    {

    u8 Local_u8ErrorFlag;

    Local_u8ErrorFlag = ok;

    switch (Copy_u8IntId)
	{
    case EXINT_u8INT0:

	switch (Copy_u8IntMode)
	    {
	case EXINT_u8RISINGEDGE:

	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC00);
	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC01);

	    break;

	case EXINT_u8FALINGEDGE:

	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC00);
	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC01);

	    break;

	case EXINT_u8LOWLEVEL:

	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC00);
	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC01);

	    break;

	case EXINT_u8LEVELCHANGE:

	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC00);
	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC01);

	    break;

	default:
	    Local_u8ErrorFlag = error;

	    break;

	    }

	break;

    case EXINT_u8INT1:

	switch (Copy_u8IntMode)
	    {
	case EXINT_u8RISINGEDGE:

	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC10);
	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC11);

	    break;

	case EXINT_u8FALINGEDGE:

	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC10);
	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC11);

	    break;

	case EXINT_u8LOWLEVEL:

	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC10);
	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC11);

	    break;

	case EXINT_u8LEVELCHANGE:

	    SET_BIT((*EXINT_u8MCUCR), EXINT_u8ISC10);
	    CLR_BIT((*EXINT_u8MCUCR), EXINT_u8ISC11);

	    break;

	default:
	    Local_u8ErrorFlag = error;

	    break;

	    }

	break;

    case EXINT_u8INT2:

	switch (Copy_u8IntMode)
	    {
	case EXINT_u8RISINGEDGE:

	    SET_BIT((*EXINT_u8MCUCSR), EXINT_u8ISC2);

	    break;

	case EXINT_u8FALINGEDGE:

	    CLR_BIT((*EXINT_u8MCUCSR), EXINT_u8ISC2);

	    break;

	default:
	    Local_u8ErrorFlag = error;

	    break;

	    }

	break;

    default:

	Local_u8ErrorFlag = error;

	break;

	}

    return Local_u8ErrorFlag;
    }

extern u8 EXINT_ENABLEINT(u8 Copy_u8IntId)
    {

    u8 Local_u8ErrorFlag;

    if (Copy_u8IntId == EXINT_u8INT0 || Copy_u8IntId == EXINT_u8INT1 || Copy_u8IntId == EXINT_u8INT2)
	{
	SET_BIT(*EXINT_u8GICR, Copy_u8IntId);

	Local_u8ErrorFlag = ok;
	}
    else
	{

	Local_u8ErrorFlag = error;
	}
    return Local_u8ErrorFlag;
    }

extern u8 EXINT_DISABLEINT(u8 Copy_u8IntId)
    {

    u8 Local_u8ErrorFlag;

    if (Copy_u8IntId == EXINT_u8INT0 || Copy_u8IntId == EXINT_u8INT1 || Copy_u8IntId == EXINT_u8INT2)
	{
	CLR_BIT(*EXINT_u8GICR, Copy_u8IntId);

	Local_u8ErrorFlag = ok;
	}
    else
	{

	Local_u8ErrorFlag = error;
	}
    return Local_u8ErrorFlag;
    }

ISR(__vector_1)
    {

    if (EXINT_PvoidEXINT0ISR == 0)
	{
	}
    else
	{
	__asm("CLI");

	EXINT_PvoidEXINT0ISR();
	__asm("SEI");
	}
    }

ISR(__vector_2)
    {

    if (EXINT_PvoidEXINT1ISR == 0)
	{
	}
    else
	{
	__asm("CLI");

	EXINT_PvoidEXINT1ISR();
	__asm("SEI");
	}
    }

ISR(__vector_3)
    {

    if (EXINT_PvoidEXINT2ISR == 0)
	{
	}
    else
	{
	__asm("CLI");

	EXINT_PvoidEXINT0ISR();

	__asm("SEI");
	}
    }

extern void EXINT_ISR0CallBackSet(void (*Copy_PvoidEXINT0ISR)(void))
    {
    EXINT_PvoidEXINT0ISR = Copy_PvoidEXINT0ISR;
    return;
    }

extern void EXINT_ISR1CallBackSet(void (*Copy_PvoidEXINT1ISR)(void))
    {
    EXINT_PvoidEXINT1ISR = Copy_PvoidEXINT1ISR;
    return;
    }

extern void EXINT_ISR2CallBackSet(void (*Copy_PvoidEXINT2ISR)(void))
    {
    EXINT_PvoidEXINT2ISR = Copy_PvoidEXINT2ISR;
    return;
    }

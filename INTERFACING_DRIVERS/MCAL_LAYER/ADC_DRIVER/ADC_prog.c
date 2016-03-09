#include"../../APPLICATION_LAYER/types.h"
#include"ADC_interface.h"  
#include"ADC_config.h" 
#include"ADC_private.h"

void ADC_u8voidInit(void)
    {

    *ADC_u8ADMUX = CONC(ADC_u8REFS1, ADC_u8REFS0, ADC_u8ADLAR, 0, 0, 0, 0, 0);

    CLR_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    return;
    }

u8 ADC_u8Read_Channel_One_Shot(u8 Copy_u8Channel_Num, u16* Copy_pu16Result)
    {

    u8 local_u8ErrorFlag;
    u8 local_8End_Of_conversion;
    u8 local_u8ADC_State;
    u8* local_pu8Result;

    local_u8ADC_State = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    if (Copy_u8Channel_Num < ADC_u8_NUMBER_OF_CHANNELS && local_u8ADC_State)

	{

	local_pu8Result = (u8*) Copy_pu16Result;

	*ADC_u8ADMUX |= Copy_u8Channel_Num;

	SET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	do
	    {

	    local_8End_Of_conversion = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	    } while (local_8End_Of_conversion);

#if ADC_u8RESOLUTION==ADC_u8TEN_BITS

	*local_pu8Result++ = *ADC_u8ADCL;

	*local_pu8Result = *ADC_u8ADCH;

#elif ADC_u8RESOLUTION==ADC_u8EIGHT_BITS

	*local_pu8Result++=*ADC_u8ADCH;

	*local_pu8Result=0x00;

#else

#error " error at choosing resolution"

#endif

	local_u8ErrorFlag = ok;

	}

    else
	{

	local_u8ErrorFlag = error;

	}

    return local_u8ErrorFlag;

    }

u8 ADC_u8Read_Channel_Multi_Shot(u8 Copy_u8Channel_Num, u16* Copy_pu16Result)
    {

    u8 local_u8ErrorFlag;
    u8 local_8End_Of_conversion;
    u8 local_u8ADC_State;
    u8* local_pu8Result;
    u16* local_pu16Result;

    local_u8ADC_State = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    if (Copy_u8Channel_Num < ADC_u8_NUMBER_OF_CHANNELS && local_u8ADC_State)

	{

	*Copy_pu16Result = 0;

	*ADC_u8ADMUX |= Copy_u8Channel_Num;

	for (u8 Local_u8LoopCounter = 0; Local_u8LoopCounter < ADC_u8NUMBER_OF_SAMPLES; Local_u8LoopCounter++)

	    {

	    local_pu8Result = (u8*) local_pu16Result;

	    SET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	    do
		{

		local_8End_Of_conversion = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

		} while (local_8End_Of_conversion);

#if ADC_u8RESOLUTION==ADC_u8TEN_BITS

	    *local_pu8Result++ = *ADC_u8ADCL;

	    *local_pu8Result = *ADC_u8ADCH;

#elif ADC_u8RESOLUTION==ADC_u8EIGHT_BITS

	    *local_pu8Result++=*ADC_u8ADCH;

	    *local_pu8Result=0x00;

#else

#error " error at choosing resolution"

#endif

	    *Copy_pu16Result += *local_pu16Result;

	    }

	*Copy_pu16Result >>= 3;

	local_u8ErrorFlag = ok;

	}

    else
	{

	local_u8ErrorFlag = error;

	}

    return local_u8ErrorFlag;

    }

void ADC_voidEnable(void)
    {

    CLR_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    return;
    }

void ADC_voidDisable(void)
    {

    SET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    return;
    }

u8 ADC_u8Read_Group(u16* Copy_pu16Result)
    {

    u8 local_u8ErrorFlag;
    u8 local_8End_Of_conversion;
    u8 local_u8ADC_State;
    u8* local_pu8Result;


    local_u8ADC_State = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    if (local_u8ADC_State)

	{

	    local_pu8Result = (u8*) Copy_pu16Result;

	for (u8 Local_u8LoopCounter = 0; Local_u8LoopCounter < ADC_u8NUMBER_OF_SAMPLES; Local_u8LoopCounter++)

	    {

	    *ADC_u8ADMUX |= Local_u8LoopCounter;

	    SET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	    do
		{

		local_8End_Of_conversion = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

		} while (local_8End_Of_conversion);

#if ADC_u8RESOLUTION==ADC_u8TEN_BITS

	    *local_pu8Result++ = *ADC_u8ADCL;

	    *local_pu8Result++ = *ADC_u8ADCH;

#elif ADC_u8RESOLUTION==ADC_u8EIGHT_BITS

	    *local_pu8Result++=*ADC_u8ADCH;

	    *local_pu8Result++=0x00;

#else

#error " error at choosing resolution"

#endif

	    }

	local_u8ErrorFlag = ok;

	}

    else
	{

	local_u8ErrorFlag = error;

	}

    return local_u8ErrorFlag;

    }

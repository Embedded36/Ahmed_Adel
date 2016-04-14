#include"../../Shared_Libraries/types.h"
#include"ADC_interface.h"  
#include"ADC_config.h" 
#include"ADC_private.h"

void ADC_u8voidInit(void)
    {

    /*Comment!: Configuration of resolution and reference voltage */
    *ADC_u8ADMUX = CONC(ADC_u8REFS1, ADC_u8REFS0, ADC_u8ADLAR, 0, 0, 0, 0, 0);

    /*Comment!: Disable ADC  */
    CLR_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    return;
    }

u8 ADC_u8Read_Channel_One_Shot(u8 Copy_u8Channel_Num, u16* Copy_pu16Result)
    {

    u8 local_u8ErrorFlag;
    u8 local_8End_Of_conversion;
    u8 local_u8ADC_State;
    u8* local_pu8Result;

    /*Comment!:check ADC enabled or disabled */
    local_u8ADC_State = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    if (Copy_u8Channel_Num < ADC_u8_NUMBER_OF_CHANNELS && local_u8ADC_State)

	{

	/*Comment!: Create u8 pointer to the result*/
	local_pu8Result = (u8*) Copy_pu16Result;

	/*Comment!: Choose ADC channel */
	*ADC_u8ADMUX |= Copy_u8Channel_Num;

	/*Comment!: Start ADC  */
	SET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	do
	    {

	    /*Comment!: Check end of conversion*/
	    local_8End_Of_conversion = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	    } while (local_8End_Of_conversion);

	/*Comment!: Return ADC result*/

#if ADC_u8RESOLUTION==ADC_u8TEN_BITS

	*(local_pu8Result++) = *ADC_u8ADCL;

	*local_pu8Result = *ADC_u8ADCH;

#elif ADC_u8RESOLUTION==ADC_u8EIGHT_BITS

	*(local_pu8Result++) = *ADC_u8ADCH;

	*local_pu8Result = 0x00;

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

    /*Comment!:check ADC enabled or disabled */
    local_u8ADC_State = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    if (Copy_u8Channel_Num < ADC_u8_NUMBER_OF_CHANNELS && local_u8ADC_State)

	{

	/*Comment!: initialize summation variable */
	*Copy_pu16Result = 0;

	/*Comment!: Choose ADC Channel*/
	*ADC_u8ADMUX |= Copy_u8Channel_Num;

	for (u8 Local_u8LoopCounter = 0; Local_u8LoopCounter < ADC_u8NUMBER_OF_SAMPLES; Local_u8LoopCounter++)

	    {

	    /*Comment!: Create u8 pointer to reading's temp variable*/
	    local_pu8Result = (u8*) local_pu16Result;

	    /*Comment!: Start conversion*/
	    SET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	    do
		{

		/*Comment!: Check end of conversion*/
		local_8End_Of_conversion = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

		} while (local_8End_Of_conversion);

	    /*Comment!: Write result to temp variable*/
#if ADC_u8RESOLUTION==ADC_u8TEN_BITS

	    *(local_pu8Result++) = *ADC_u8ADCL;

	    *local_pu8Result = *ADC_u8ADCH;

#elif ADC_u8RESOLUTION==ADC_u8EIGHT_BITS

	    *(local_pu8Result++) = *ADC_u8ADCH;

	    *local_pu8Result = 0x00;

#else

#error " error at choosing resolution"

#endif
	    /*Comment!: add samples to summation tank*/
	    *Copy_pu16Result += *local_pu16Result;

	    }

	/*Comment!: return samples' average*/
	*Copy_pu16Result /= ADC_u8NUMBER_OF_SAMPLES;

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

    /*Comment!: Enable ADC*/
    SET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    return;
    }

void ADC_voidDisable(void)
    {

    /*Comment!: Disable ADC */
    CLR_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    return;
    }

u8 ADC_u8Read_Group(u16* Copy_pu16Result)
    {

    u8 local_u8ErrorFlag;
    u8 local_8End_Of_conversion;
    u8 local_u8ADC_State;
    u8* local_pu8Result;

    /*Comment!:check ADC enabled or disabled */
    local_u8ADC_State = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADEN);

    if (local_u8ADC_State)

	{

	/*Comment!: Create u8 pointer to result*/
	local_pu8Result = (u8*) Copy_pu16Result;

	for (u8 Local_u8LoopCounter = 0; Local_u8LoopCounter < ADC_u8NUMBER_OF_SAMPLES; Local_u8LoopCounter++)

	    {

	    /*Comment!: Choose ADC channel*/
	    *ADC_u8ADMUX |= Local_u8LoopCounter;

	    /*Comment!: Start Conversion*/
	    SET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

	    do
		{

		/*Comment!: Check end of conversion*/
		local_8End_Of_conversion = GET_BIT(*ADC_u8ADCSRA, ADC_u8ADSC);

		} while (local_8End_Of_conversion);

	    /*Comment!: write back result of one channel*/
#if ADC_u8RESOLUTION==ADC_u8TEN_BITS

	    *(local_pu8Result++) = *ADC_u8ADCL;

	    *(local_pu8Result++) = *ADC_u8ADCH;

#elif ADC_u8RESOLUTION==ADC_u8EIGHT_BITS

	    *(local_pu8Result++) = *ADC_u8ADCH;

	    *(local_pu8Result++) = 0x00;

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

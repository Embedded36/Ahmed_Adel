/*
 * ADC_TEST.c
 *
 *  Created on: Mar 11, 2016
 *      Author: Ahmed
 */
#include"../../../APPLICATION_LAYER/types.h"
#include"../ADC_interface.h"
#include"../../DIO_DRIVER/DIO_interface.h"

int main()
    {

    f32 ADC_VAL;

    /*Comment!: DIO init*/
    DIO_voidInit();

    /*Comment!: ADC init*/
    ADC_u8voidInit();

    /*Comment!: ADC enable*/
    ADC_voidEnable();

    /*Comment!: Configure port1(portb) as output*/
    DIO_u8WritePortDir(DIO_u8PORT1, 0xff);

    while (1)
	{

	/*Comment!: Create u8 pointer to reading's temp variable*/
	// ADC_u8Read_Channel_Multi_Shot(ADC_u8Channel0, &ADC_VAL);
	ADC_u8Read_Channel_One_Shot(ADC_u8Channel0, &ADC_VAL);
	/*Comment!: Write first 8 bits of output at port1*/
	// DIO_u8WritePortVal(DIO_u8PORT1,(u16)(ADC_VAL));
	if (ADC_VAL > 3)
	    {
	    DIO_u8WritePortVal(DIO_u8PORT1, 0xff);
	    }
	else
	    {
	    DIO_u8WritePortVal(DIO_u8PORT1, 0x00);
	    }
		  //  DIO_u8WritePortVal(DIO_u8PORT1, ADC_VAL);

	}

    return 0;

    }


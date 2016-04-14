/*
 * SPI_TEST.c

 *
 *  Created on: Apr 14, 2016
 *      Author: Ahmed
 */
#include "../../../Shared_Libraries/types.h"
#include "../../../Shared_Libraries/interrupt.h"
#include "../../DIO_DRIVER/DIO_interface.h"
#include "../SPI_interface.h"

u8 val = 0;

void led(void)
    {
    val++;
    DIO_u8WritePortVal(DIO_u8PORT3, val);

    return;
    }
void main()
    {

    u8 temp[2];

    int valueDAC = 4095;

    temp[0] = (valueDAC >> 8) & 0x0F; // Store valueDAC[11..8] to temp[3..0]
    temp[0] |= 0x10; // Define DAC setting, see MCP4921 datasheet ,Gain x2

    temp[1] = 0X45;

    DIO_voidInit();
    SPI_voidInit();
    Enable_Global_INT();

    SPI_ISRCallBackSet(led);

    while (1)
	{
	SPI_u8Send_Packet(&temp, NULL,
	SPI_u8SLAVE1, 2); // Send high byte via SPI
	}

    return;

    }

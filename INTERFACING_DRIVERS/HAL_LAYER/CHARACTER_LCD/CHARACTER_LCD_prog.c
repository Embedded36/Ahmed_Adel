#include"../../APPLICATION_LAYER/types.h"
#include"../../APPLICATION_LAYER/Delay.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"CHARACTER_LCD_interface.h"  
#include"CHARACTER_LCD_config.h" 
#include"CHARACTER_LCD_private.h"

//int main()
//    {
//
//    DIO_voidInit();
//
//    CHARACTER_LCD_voidInit();
//
//    CHARACTER_LCD_voidWriteCommand(0b01000000);
//
//    CHARACTER_LCD_voidWriteData(0xff);
//    CHARACTER_LCD_voidWriteData(0x00);
//    CHARACTER_LCD_voidWriteData(0xff);
//    CHARACTER_LCD_voidWriteData(0x00);
//
//    CHARACTER_LCD_voidWriteData(0xff);
//    CHARACTER_LCD_voidWriteData(0x00);
//    CHARACTER_LCD_voidWriteData(0xff);
//    CHARACTER_LCD_voidWriteData(0x00);
//
//    CHARACTER_LCD_voidWriteCommand(0x80);
//
//    CHARACTER_LCD_voidWriteData(0x00);
//
//
//    return 0;
//
//    }


void CHARACTER_LCD_voidInit(void)
    {

    CHARACTER_LCD_voidWriteCommand(0b00110000);

    voidDELAY_MS(20);

    CHARACTER_LCD_voidWriteCommand(0b00110000);

    voidDELAY_MS(1);

    CHARACTER_LCD_voidWriteCommand(0b00110000);

    CHARACTER_LCD_voidWriteCommand(0b00111100);

    CHARACTER_LCD_voidWriteCommand(0b00000110);

    CHARACTER_LCD_voidWriteCommand(0b00001100);


    return;
    }

void CHARACTER_LCD_voidWriteCommand(u8 Copy_u8Command)
    {

    u8 local_u8Command_Bit;

    DIO_u8WritePinVal(CHARACTER_LCD_u8REGISTER_SELECT, DIO_u8LOW);

    DIO_u8WritePinVal(CHARACTER_LCD_u8READ_WRITE, DIO_u8LOW);

    DIO_u8WritePinVal(CHARACTER_LCD_u8ENABLE, DIO_u8HIGH);

    for (u8 local_u8LoopCounter = 0; local_u8LoopCounter < CHARACTER_LCD_NUM_OF_DATA_PINS; local_u8LoopCounter++)
	{

	local_u8Command_Bit = GET_BIT(Copy_u8Command, local_u8LoopCounter);

	DIO_u8WritePinVal(CHARACTER_LCD_u8Data_Pins[local_u8LoopCounter], local_u8Command_Bit);

	}

///delay

    DIO_u8WritePinVal(CHARACTER_LCD_u8ENABLE, DIO_u8LOW);

    return;
    }

void CHARACTER_LCD_voidWriteData(u8 Copy_u8Data)
    {

    u8 local_u8Data_Bit;

    DIO_u8WritePinVal(CHARACTER_LCD_u8REGISTER_SELECT, DIO_u8HIGH);

    DIO_u8WritePinVal(CHARACTER_LCD_u8READ_WRITE, DIO_u8LOW);

    DIO_u8WritePinVal(CHARACTER_LCD_u8ENABLE, DIO_u8HIGH);

    for (u8 local_u8LoopCounter = 0; local_u8LoopCounter < CHARACTER_LCD_NUM_OF_DATA_PINS; local_u8LoopCounter++)
	{

	local_u8Data_Bit = GET_BIT(Copy_u8Data, local_u8LoopCounter);

	DIO_u8WritePinVal(CHARACTER_LCD_u8Data_Pins[local_u8LoopCounter], local_u8Data_Bit);

	}

///delay

    DIO_u8WritePinVal(CHARACTER_LCD_u8ENABLE, DIO_u8LOW);

    return;
    }


#include"../../Shared_Libraries/types.h"
#include"../../Shared_Libraries/Delay.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"CHARACTER_LCD_interface.h"  
#include"CHARACTER_LCD_config.h" 
#include"CHARACTER_LCD_private.h"

const u8 CHARACTER_LCD_u8Data_Pins[CHARACTER_LCD_u8NUM_OF_DATA_PINS] =
    {
	    CHARACTER_LCD_u8DATA0,
	    CHARACTER_LCD_u8DATA1,
	    CHARACTER_LCD_u8DATA2,
	    CHARACTER_LCD_u8DATA3,
	    CHARACTER_LCD_u8DATA4,
	    CHARACTER_LCD_u8DATA5,
	    CHARACTER_LCD_u8DATA6,
	    CHARACTER_LCD_u8DATA7
    };

void CHARACTER_LCD_voidInit(void)
    {

    /*Comment!: Initialization sequence of lcd */
    CHARACTER_LCD_voidWriteCommand(0b00110000);

    voidDELAY_MS(20);

    CHARACTER_LCD_voidWriteCommand(0b00110000);

    voidDELAY_MS(1);

    CHARACTER_LCD_voidWriteCommand(0b00110000);

    /*Comment!: Commands to set up features of lcd */
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

    for (u8 local_u8LoopCounter = 0; local_u8LoopCounter < CHARACTER_LCD_u8NUM_OF_DATA_PINS; local_u8LoopCounter++)
	{

	local_u8Command_Bit = GET_BIT(Copy_u8Command, local_u8LoopCounter);

	DIO_u8WritePinVal(CHARACTER_LCD_u8Data_Pins[local_u8LoopCounter], local_u8Command_Bit);

	}

    DIO_u8WritePinVal(CHARACTER_LCD_u8ENABLE, DIO_u8LOW);

    return;
    }

void CHARACTER_LCD_voidWriteData(u8 Copy_u8Data)
    {

    u8 local_u8Data_Bit;

    DIO_u8WritePinVal(CHARACTER_LCD_u8REGISTER_SELECT, DIO_u8HIGH);

    DIO_u8WritePinVal(CHARACTER_LCD_u8READ_WRITE, DIO_u8LOW);

    DIO_u8WritePinVal(CHARACTER_LCD_u8ENABLE, DIO_u8HIGH);

    for (u8 local_u8LoopCounter = 0; local_u8LoopCounter < CHARACTER_LCD_u8NUM_OF_DATA_PINS; local_u8LoopCounter++)
	{

	local_u8Data_Bit = GET_BIT(Copy_u8Data, local_u8LoopCounter);

	DIO_u8WritePinVal(CHARACTER_LCD_u8Data_Pins[local_u8LoopCounter], local_u8Data_Bit);

	}

    DIO_u8WritePinVal(CHARACTER_LCD_u8ENABLE, DIO_u8LOW);

    return;
    }

u8 CHARACTER_LCD_voidClear(u8 Local_u8LineId)
    {

    u8 Local_u8ErrorFlag;

    /*Comment!: Check that sent parameters are in range*/
    if (Local_u8LineId < (CHARACTER_LCD_u8AllLines + 1))
	{

	switch (Local_u8LineId)

	    {

	case CHARACTER_LCD_u8LINE_1:

	    CHARACTER_LCD_voidWrite((u8*)"                ", CHARACTER_LCD_u8LINE_1, 0);
	    break;

	case CHARACTER_LCD_u8LINE_2:

	    CHARACTER_LCD_voidWrite((u8*)"                ", CHARACTER_LCD_u8LINE_2, 0);
	    break;

	case CHARACTER_LCD_u8AllLines:

	    CHARACTER_LCD_voidWriteCommand(1);
	    break;

	default:
	    break;

	    }

	Local_u8ErrorFlag = ok;

	}
    else
	{

	Local_u8ErrorFlag = error;

	}

    return Local_u8ErrorFlag;

    }

u8 CHARACTER_LCD_voidWrite(u8* Copy_u8String, u8 Copy_u8Line, u8 Copy_u8CharId)
    {

    u8 Local_u8CharCounter = 0;

    u8 Local_u8ErrorFlag;

    /*Comment!: Check that sent parameters are in range*/
    if (Copy_u8Line < CHARACTER_LCD_u8NumberOfLines && Copy_u8CharId < CHARACTER_LCD_u8MaxLineChars)
	{

	/*Comment!: Move to char position in ddram*/
	switch (Copy_u8Line)

	    {

	case CHARACTER_LCD_u8LINE_1:

	    CHARACTER_LCD_voidWriteCommand(CHARACTER_LCD_u8line1Id + Copy_u8CharId);

	    break;

	case CHARACTER_LCD_u8LINE_2:

	    CHARACTER_LCD_voidWriteCommand(CHARACTER_LCD_u8line2Id + Copy_u8CharId);

	    break;

	default:

	    break;

	    }
	/*Comment!: Check didn't reach end of string or end of line*/
	while (Local_u8CharCounter < CHARACTER_LCD_u8MaxLineChars && (*Copy_u8String != '\0'))
	    {

	    CHARACTER_LCD_voidWriteData(*Copy_u8String);

	    Local_u8CharCounter++;

	    Copy_u8String++;
	    }

	Local_u8ErrorFlag = ok;

	}
    else
	{
	Local_u8ErrorFlag = error;
	}

    return Local_u8ErrorFlag;

    }

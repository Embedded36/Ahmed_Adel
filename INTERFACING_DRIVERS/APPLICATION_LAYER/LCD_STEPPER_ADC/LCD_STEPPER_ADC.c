#include"../types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"../../MCAL_LAYER/ADC_DRIVER/ADC_interface.h"
#include"../../HAL_LAYER/CHARACTER_LCD/CHARACTER_LCD_interface.h"
#include "../../HAL_LAYER/SREPPER_MOTOR/STEPPER_MOTOR_interface.h"
#include "../../HAL_LAYER/TACTILE_SWITCH/TACTILE_SWITCH_interface.h"

int main()
    {

    u8 switch_result;
    u16 temp;
    u8 counter;

    DIO_voidInit();

    ADC_u8voidInit();
    STEPPER_MOTOR_voidInit();
    CHARACTER_LCD_voidInit();

    TACTILE_SWITCH_voidInit();

    ADC_voidEnable();
    //goto cgram
    //  CHARACTER_LCD_voidWriteCommand(0b01000000);
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
//    CHARACTER_LCD_voidWriteCommand(0b11000000);
//
//    CHARACTER_LCD_voidWriteData(0x00);

   // DIO_u8WritePortDir(DIO_u8PORT2, 0xff);

    while (1)
	{

	TACTILE_SWITCH_u8Read(TACTILE_SWITCH_u8SWITCH1ID,&switch_result);

	counter++;

	ADC_u8Read_Channel_One_Shot(ADC_u8Channel0, &temp);

	if (temp < 128)
	    {
	    if (switch_result == TACTILE_SWITCH_u8PRESSED)
		{
		CHARACTER_LCD_voidWrite("ASAF ", CHARACTER_LCD_u8LINE_1, 0);
		}
	    else
		{
		}

	    switch ((u8) temp / (u8) 26)
		{

	    case 0:

		CHARACTER_LCD_voidWrite("Speed 4 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("LEFT ", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 1)
		    {
		    STEPPER_MOTOR_RotateLeft();
		    counter = 0;
		    }
		else
		    {

		    }
		break;
	    case 1:
		CHARACTER_LCD_voidWrite("Speed 3 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("LEFT ", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 2)
		    {
		    STEPPER_MOTOR_RotateLeft();
		    counter = 0;
		    }
		else
		    {

		    }
		break;
	    case 2:
		CHARACTER_LCD_voidWrite("Speed 2 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("LEFT ", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 3)
		    {
		    STEPPER_MOTOR_RotateLeft();
		    counter = 0;
		    }
		else
		    {

		    }
		break;
	    case 3:
		CHARACTER_LCD_voidWrite("Speed 1 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("LEFT ", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 4)
		    {
		    STEPPER_MOTOR_RotateLeft();
		    counter = 0;
		    }
		else
		    {

		    }
		break;
	    case 4:
		CHARACTER_LCD_voidWrite("Speed 0 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("STOP ", CHARACTER_LCD_u8LINE_1, 0);

		break;
	    default:
//		CHARACTER_LCD_voidWrite("case D ", CHARACTER_LCD_u8LINE_2, 0);

		break;

		}
	    }
	else
	    {

	    if (switch_result == TACTILE_SWITCH_u8PRESSED)
		{
		CHARACTER_LCD_voidWrite("ASAF ", CHARACTER_LCD_u8LINE_1, 0);
		}
	    else
		{
		}
	    temp = temp - 127;

	    switch ((u8)4-((u8) temp / (u8) 26))
		{

	    case 0:
		CHARACTER_LCD_voidWrite("Speed 4 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("RIGHT", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 1)
		    {
		    STEPPER_MOTOR_RotateRight();
		    counter = 0;
		    }
		else
		    {

		    }
		break;
	    case 1:

		CHARACTER_LCD_voidWrite("Speed 3 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("RIGHT", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 2)
		    {
		    STEPPER_MOTOR_RotateRight();
		    counter = 0;
		    }
		else
		    {

		    }
		break;
	    case 2:
		CHARACTER_LCD_voidWrite("Speed 2 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("RIGHT", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 3)
		    {
		    STEPPER_MOTOR_RotateRight();
		    counter = 0;
		    }
		else
		    {

		    }
		break;
	    case 3:
		CHARACTER_LCD_voidWrite("Speed 1 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("RIGHT", CHARACTER_LCD_u8LINE_1, 0);

		if (counter >= 4)
		    {
		    STEPPER_MOTOR_RotateRight();
		    counter = 0;
		    }
		else
		    {

		    }
		break;

	    case 4:
		CHARACTER_LCD_voidWrite("Speed 0 ", CHARACTER_LCD_u8LINE_2, 0);
		CHARACTER_LCD_voidWrite("STOP ", CHARACTER_LCD_u8LINE_1, 0);

		break;
	    default:
		CHARACTER_LCD_voidWrite("case D ", CHARACTER_LCD_u8LINE_2, 0);

		break;

		}

	    }
//	DIO_u8WritePortVal(DIO_u8PORT2, (u8) temp / (u8) 26);

	}

    return 0;

    }


#include"../types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"../../MCAL_LAYER/ADC_DRIVER/ADC_interface.h"
#include"../../HAL_LAYER/CHARACTER_LCD/CHARACTER_LCD_interface.h"
#include "../../HAL_LAYER/SREPPER_MOTOR/STEPPER_MOTOR_interface.h"

int main()
    {

    u16 temp;

    DIO_voidInit();

    ADC_u8voidInit();
    STEPPER_MOTOR_voidInit();
    CHARACTER_LCD_voidInit();

    ADC_voidEnable();
    //goto cgram
    CHARACTER_LCD_voidWriteCommand(0b01000000);

    CHARACTER_LCD_voidWriteData(0xff);
    CHARACTER_LCD_voidWriteData(0x00);
    CHARACTER_LCD_voidWriteData(0xff);
    CHARACTER_LCD_voidWriteData(0x00);

    CHARACTER_LCD_voidWriteData(0xff);
    CHARACTER_LCD_voidWriteData(0x00);
    CHARACTER_LCD_voidWriteData(0xff);
    CHARACTER_LCD_voidWriteData(0x00);

    CHARACTER_LCD_voidWriteCommand(0b11000000);

    CHARACTER_LCD_voidWriteData(0x00);

    while (1)
	{

	ADC_u8Read_Channel_One_Shot(ADC_u8Channel0, &temp);

	    CHARACTER_LCD_voidWriteCommand(0b11000000);

	if (temp < 128)
	    {
	    STEPPER_MOTOR_RotateLeft();
	    CHARACTER_LCD_voidWriteData('l');
	    }
	else
	    {
	    STEPPER_MOTOR_RotateRight();
	    CHARACTER_LCD_voidWriteData('r');

	    }
	}

    return 0;

    }


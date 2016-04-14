#include "../types.h"
#include"../../MCAL_LAYER/TIMER0/TIMER0_interface.h"
#include "../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include"../../HAL_LAYER/KEYPAD/KEYPAD_interface.h"

int main()
    {

    u16 temp = 0;

    u8 keypad;

    u8 toggle = 0;
    Keypad_u16Switches APP_Keypad;

    DIO_voidInit();
    TIMER0_voidINIT();
    KEYPAD_voidInit();

    while (1)
	{

	temp = TIMER0_u16readMS();

	APP_Keypad = KEYPAD_Keypad_u16SwitchesRead();

	switch (APP_Keypad.KEYPAD_u16Switches)
	    {

	case (1 << 0):

	    temp = 1;
	    break;

	case (1 << 1):

	    temp = 2;
	    break;

	case (1 << 2):

	    temp = 3;
	    break;

	case (1 << 3):

	    temp = 4;
	    break;

	case (1 << 4):

	    temp = 5;
	    break;

	case (1 << 5):

	    temp = 6;
	    break;

	case (1 << 6):

	    temp = 7;
	    break;

	case (1 << 7):

	    temp = 8;
	    break;

	case (1 << 8):

	    temp = 9;
	    break;

	case (1 << 9):

	    temp = 10;
	    break;

	case (1 << 10):

	    temp = 11;
	    break;

	case (1 << 11):

	    temp = 12;
	    break;

	case (1 << 12):

	    temp = 13;
	    break;

	case (1 << 13):

	    temp = 14;
	    break;

	case (1 << 14):

	    temp = 15;
	    break;

	case (1 << 15):

	    temp = 16;
	    break;

	default:

	    break;

	    }

	keypad = TIMER0_u16readMS();

	if (keypad >= temp)
	    {
	    toggle = !toggle;
	    }
	else
	    {

	    }

	DIO_u8WritePinVal(DIO_u8PIN30, toggle);

	}
    return 0;
    }

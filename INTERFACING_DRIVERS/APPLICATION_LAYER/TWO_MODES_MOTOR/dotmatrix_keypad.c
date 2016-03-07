//keypad test
#include"../types.h"
#include"../../MCAL_LAYER/DIO_DRIVER/DIO_interface.h"
#include "../../HAL_LAYER/TACTILE_SWITCH/TACTILE_SWITCH_interface.h"
#include"../../HAL_LAYER/KEYPAD/KEYPAD_interface.h"

#define DIO_u8PORTC   ((volatile u8*)(0x35))
#define STARTING_POINT 0
#define SWITCH_PRESSED 1
#define CONTINOUS_MODE 2
#define CLICK_MODE  3
#define WAITING_FOR_SWITCH_RELEASE 4
#define TIME_LIMIT 70
#define LEFT 0
#define RIGHT 1
#define SH_CP     DIO_u8PIN24
#define ST_CP     DIO_u8PIN25
#define DS        DIO_u8PIN26
#define DISPLAY_RIGHT 0
#define DISPLAY_LEFT 1
#define DISPLAY_OFF 2
#define GET_BIT(Reg,Bit_no)                   (((Reg)>>(Bit_no))&1)

int main()
    {

    u8 local_u8state = STARTING_POINT;
    u8 local_u8SwitchRead;
    u16 local_u16Counter;
    u8 local_Direction_Flag = RIGHT;
    u8 local_Display_Flag = DISPLAY_OFF;
    Keypad_u16Switches keypad;
    u8 local_u8MotorPin1Val[2] =
	{
	DIO_u8HIGH, DIO_u8LOW
	};
    u8 LOCAL_U8NAMEMATRIX[17][8] =
	{

	    {
	    0, 0, 0, 0, 0, 0, 0, 0
	    },
	    {
	    0b10111000, 0b10100000, 0b10100000, 0b10111000, 0b10101000, 0b10101000, 0b10111000, 0b10000000
	    },
	    {
	    0b10111000, 0b10100000, 0b10100000, 0b10111000, 0b10001000, 0b10001000, 0b10111000, 0b10000000
	    },
	    {
	    0b10101000, 0b10101000, 0b10101000, 0b10111000, 0b10001000, 0b10001000, 0b10001000, 0b10000000
	    },
	    {
	    0b10111000, 0b10001000, 0b10001000, 0b10111000, 0b10001000, 0b10001000, 0b10111000, 0b10000000
	    },
	    {
	    0b10111000, 0b10001000, 0b10001000, 0b10111000, 0b10100000, 0b10100000, 0b10111000, 0b10000000
	    },
	    {
	    0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b10001000
	    },
	    {
	    0B10001000, 0B10010100, 0B10100010, 0B10100010, 0B10010100, 0B10001000, 0B10000000, 0B10000000
	    },
	    {
	    0B00010000, 0B00101000, 0B01000100, 0B00101000, 0B00010000, 0B00100000, 0B01000000, 0B00000000
	    },
	    {
	    0B00010000, 0B00101000, 0B01000100, 0B00101000, 0B00010000, 0B00101000, 0B01000100, 0B00111000
	    },
	    {
	    0b11111100, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000, 0b00000000
	    },
	    {
	    0b11111000, 0b10000000, 0b10000000, 0b10000000, 0b11111000, 0b10001000, 0b10001000, 0b11111000
	    },
	    {
	    0b00111111, 0b00100000, 0b00100000, 0b00111000, 0b00000100, 0b00000010, 0b00000010, 0b00111100
	    },

	    {
	    0B10001000, 0B10001000, 0B11111000, 0B00001000, 0B00001000, 0B00001000, 0B00001000, 0B00000000
	    },

	    {
	    0B00000000, 0B11111000, 0B00001000, 0B00010000, 0B00010000, 0B00001000, 0B00001000, 0B11110000
	    },

	    {
	    0B11000000, 0B00100000, 0B00010000, 0B00010000, 0B00100000, 0B01000000, 0B11111000, 0B00000000
	    },
	    {
	    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
	    }
	};

    DIO_voidInit();

//    TACTILE_SWITCH_voidInit();

    KEYPAD_voidInit();

    *DIO_u8PORTC = 0x0f;

    while (1)

	{

//	TACTILE_SWITCH_u8Read(TACTILE_SWITCH_u8SWITCH1ID, &local_u8SwitchRead);

	/*Comment!:Display at Dot Matrix */
	for (u8 j = 0; j < 8; j++)
	    {

	    DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
	    DIO_u8WritePinVal(ST_CP, DIO_u8LOW);

	    for (u8 a = 0; a < 8; a++)
		{

		if (a != j)
		    {
		    DIO_u8WritePinVal(DS,
		    DIO_u8HIGH);
		    }
		else
		    {
		    DIO_u8WritePinVal(DS,
		    DIO_u8LOW);
		    }
		DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
		DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
		}

	    for (u8 i = 0; i < 8; i++)
		{
		DIO_u8WritePinVal(DS, GET_BIT(LOCAL_U8NAMEMATRIX[local_Display_Flag][j], i));
		DIO_u8WritePinVal(SH_CP, DIO_u8HIGH);
		DIO_u8WritePinVal(SH_CP, DIO_u8LOW);
		}

	    DIO_u8WritePinVal(ST_CP, DIO_u8HIGH);

	    //////////start of switch

	    keypad = KEYPAD_Keypad_u16SwitchesRead();

	    switch (keypad.KEYPAD_u16Switches)

		{

	    case (1 << 0):
		local_Display_Flag = 1;
		break;

	    case (1 << 1):
		local_Display_Flag = 2;
		break;

	    case (1 << 2):
		local_Display_Flag = 3;

		break;

	    case (1 << 3):
		local_Display_Flag = 4;

		break;

	    case (1 << 4):
		local_Display_Flag = 5;

		break;

	    case (1 << 5):
		local_Display_Flag = 6;

		break;

	    case (1 << 6):
		local_Display_Flag = 7;

		break;

	    case (1 << 7):
		local_Display_Flag = 8;

		break;

	    case (1 << 8):
		local_Display_Flag = 9;

		break;

	    case (1 << 9):
		local_Display_Flag = 10;

		break;

	    case (1 << 10):
		local_Display_Flag = 11;

		break;

	    case (1 << 11):
		local_Display_Flag = 12;

		break;

	    case (1 << 12):
		local_Display_Flag = 13;

		break;
	    case (1 << 13):
		local_Display_Flag = 14;

		break;
	    case (1 << 14):
		local_Display_Flag = 15;

		break;
	    case (1 << 15): //1
		local_Display_Flag = 16;

		break;
	    default:
		local_Display_Flag = 0;
		break;

		}

	    }

	/*comment!: end of displaying at dot matrix*/

	}

    return 0;
    }

